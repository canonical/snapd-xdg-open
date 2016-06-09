#include <gio/gio.h>

int
main (int   argc,
      char *argv[])
{
  g_autoptr(GDBusConnection) bus = NULL;
  g_autoptr(GVariant) result = NULL;
  g_autoptr(GError) error = NULL;

  if (argc != 2)
    {
      g_printerr ("syntax: %s <url>\n", argv[0]);
      return 1;
    }

  bus = g_bus_get_sync (G_BUS_TYPE_SESSION, NULL, &error);

  if (bus == NULL)
    {
      g_printerr ("error: %s\n", error->message);
      return 1;
    }

  result = g_dbus_connection_call_sync (bus,
                                        "com.canonical.SafeLauncher",
                                        "/",
                                        "com.canonical.SafeLauncher",
                                        "OpenURL",
                                        g_variant_new ("(s)", argv[1]),
                                        G_VARIANT_TYPE_UNIT,
                                        G_DBUS_CALL_FLAGS_NONE,
                                        -1,
                                        NULL,
                                        &error);

  if (result == NULL)
    {
      g_printerr ("error: %s\n", error->message);
      return 1;
    }

  return 0;
}
