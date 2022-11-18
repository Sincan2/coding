#!/bin/sh
curl -s -S -L https://raw.githubusercontent.com/AdguardTeam/AdGuardHome/master/scripts/install.sh | sh -s -- -v -u
 
# BY Sincan2
uci -q delete dhcp.@dnsmasq[0].noresolv
uci -q delete dhcp.@dnsmasq[0].cachesize
uci set dhcp.@dnsmasq[0].rebind_protection='1'
uci -q delete dhcp.@dnsmasq[0].server
uci -q delete dhcp.@dnsmasq[0].port
uci -q delete dhcp.lan.dhcp_option
uci -q delete dhcp.lan.dns
 
# Network Configuration
# Disable peer/ISP DNS
uci set network.wan.peerdns="1"
uci set network.wan6.peerdns="1"
 
# Configure DNS provider to Google DNS
uci -q delete network.wan.dns
uci add_list network.wan.dns="8.8.8.8"
uci add_list network.wan.dns="8.8.4.4"
 
# Configure IPv6 DNS provider to Google DNS
uci -q delete network.wan6.dns
uci add_list network.wan6.dns="2001:4860:4860::8888"
uci add_list network.wan6.dns="2001:4860:4860::8844"
 
# Save and apply
uci commit dhcp
uci commit network
/etc/init.d/network restart
/etc/init.d/dnsmasq restart
/etc/init.d/odhcpd restart
