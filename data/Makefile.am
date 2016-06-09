dbusservicedir = ${datadir}/dbus-1/services

dbusservice_DATA = com.canonical.SafeLauncher.service

com.canonical.SafeLauncher.service: Makefile
	$(AM_V_GEN) (echo '[D-BUS Service]'; \
	             echo 'Name=com.canonical.SafeLauncher.service'; \
	             echo 'Exec=${libexecdir}/snappy-url-helper') > $@.tmp && \
	            mv $@.tmp $@
