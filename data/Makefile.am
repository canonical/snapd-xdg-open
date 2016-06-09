dbusservicedir = ${datadir}/dbus-1/services

dbusservice_DATA = com.canonical.SnapdXDGOpen.service

com.canonical.SnapdXDGOpen.service: Makefile
	$(AM_V_GEN) (echo '[D-BUS Service]'; \
	             echo 'Name=com.canonical.SnapdXDGOpen.service'; \
	             echo 'Exec=${libexecdir}/snapd-xdg-open') > $@.tmp && \
	            mv $@.tmp $@
