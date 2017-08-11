/*
 * snapd-xdg-open
 *
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <gio/gio.h>

int
main (int   argc,
      char *argv[])
{
  GDBusConnection *bus = NULL;
  GVariant *result = NULL;
  GError *error = NULL;
  int retval = 0;

  if (argc != 2)
    {
      g_printerr ("syntax: %s <url>\n", argv[0]);
      retval = 1;
      goto out;
    }

  bus = g_bus_get_sync (G_BUS_TYPE_SESSION, NULL, &error);

  if (bus == NULL)
    {
      g_printerr ("error: %s\n", error->message);
      retval = 1;
      goto out;
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
      retval = 1;
      goto out;
    }

out:
  g_clear_object (&bus);
  g_variant_unref (result);
  g_clear_error (&error);

  return retval;
}
