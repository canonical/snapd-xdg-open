dbusservicedir = ${datadir}/dbus-1/services

dbusservice_DATA = com.canonical.SafeLauncher.service

EXTRA_DIST = xdg-open

com.canonical.SafeLauncher.service: Makefile
	$(AM_V_GEN) (echo '[D-BUS Service]'; \
	             echo 'Name=com.canonical.SafeLauncher'; \
	             echo 'Exec=${libexecdir}/snapd-xdg-open') > $@.tmp && \
	            mv $@.tmp $@
