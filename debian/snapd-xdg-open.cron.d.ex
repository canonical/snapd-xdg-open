#
# Regular cron jobs for the snapd-xdg-open package
#
0 4	* * *	root	[ -x /usr/bin/snapd-xdg-open_maintenance ] && /usr/bin/snapd-xdg-open_maintenance
