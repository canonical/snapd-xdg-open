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
  int rc = 0;
  GDBusConnection* bus = NULL;
  GVariant* result = NULL;
  GError* error = NULL;

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

  g_object_unref(bus);

  if (result == NULL)
    {
      g_printerr ("error: %s\n", error->message);
      g_error_free(error);
      rc = 1;
    }
  else
    {
      g_variant_unref(result);
      rc = 0;
    }

  return rc;
}
