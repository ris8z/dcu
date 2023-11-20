#!/usr/bin/env python3

import sys

url = sys.argv[1]

port = None
query = None
fragment = None

scheme, url = url.split("//")
scheme = scheme[:-1]

host_port = url.split("/")[0]
url = "/".join(url.split("/")[1:])

if len(host_port.split(":")) > 1:
    host, port = host_port.split(":")
else:
    host = host_port

if len(url.split("#")) > 1:
    fragment = url.split("#")[1]
    url = url.split("#")[0]

if len(url.split("?")) > 1:
    query = url.split("?")[1]
    url = url.split("?")[0]

path = "/" + url

print("scheme:", scheme)
print("host:", host)
if port:
    print("port:", port)
print("path:", path)
if query:
    print("query-string:", query)
if fragment:
    print("fragment-id:", fragment)
