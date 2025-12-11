#SECTION - docker network types

+-------------------+
| default bridge    | <- container-to-container communication con DNS interno
|                   |    (solo nello stesso bridge)
+-------------------+

+-------------------+
| host              | <- container usa rete host, nessun NAT
+-------------------+

+-------------------+
| overlay           | <- multi-host (swarm), comunica container su host diversi
+-------------------+

+-------------------+
| none              | <- container isolato, nessuna interfaccia di rete
+-------------------+

#SECTION - connection layers

| Livello           | Cosa significa                                                                       |
| ----------------- | ------------------------------------------------------------------------------------ |
| container network | Stack di interfacce virtuali dentro il container                                     |
| Docker network    | Livello logico creato da Docker (`bridge`, `overlay`) che collega container tra loro |
| host network      | Container condivide stack di rete dell’host (no NAT, stesse IP e porte)              |

#SECTION - layers example

host eth0:192.168.1.10
+-----------------------------------+
| bridge network (docker0)          |
| 172.17.0.0/16                     |
| container1:172.17.0.2             |
| container2:172.17.0.3             |
+-----------------------------------+

#SECTION - DNS

DNS TABLE: container-name <-> container-ip in docker network
to connect to container2 from container1:
I can do:
    curl 172.17.0.3:PORT
Or:
    curl container2:PORT

#SECTION - docker network inspect inception
[
    {
        "Name": "inception",
        "Id": "a4dc448f42a108509e64b1f41b3533fbe5898e9b60ece9edcfe679f8d96ed4dd",
        "Created": "2025-12-09T16:55:22.464529827Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv4": true,
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": null,
            "Config": [
                {
                    "Subnet": "172.18.0.0/16",
                    "Gateway": "172.18.0.1"
                }
            ]
        },
        "Internal": false,
        "Attachable": false,
        "Ingress": false,
        "ConfigFrom": {
            "Network": ""
        },
        "ConfigOnly": false,
        "Containers": {
            "1a4634bfcf9105632f3d8a028cd75ffebada30d4a01869405d62cb686cf861da": {
                "Name": "nginx",
                "EndpointID": "7f7cf658030c3c7d32f24d86d3a5636228061cba9927f1df3c9eca7663d360b1",
                "MacAddress": "36:58:59:dc:f1:aa",
                "IPv4Address": "172.18.0.4/16",
                "IPv6Address": ""
            },
            "1bde4042dd32486b48e8bd368ff8a3fa63113c0c703a079ab44da8a4ed6fc927": {
                "Name": "wordpress",
                "EndpointID": "599e7f8d4f8d66089418501416696a26538527ee98468a015d22949135e926fb",
                "MacAddress": "f6:e2:66:ae:58:91",
                "IPv4Address": "172.18.0.3/16",
                "IPv6Address": ""
            },
            "b7e078cc34981e34f39a5a8d9f5d6dfde3540670c3809d492d7a891ef3ba513d": {
                "Name": "mariadb",
                "EndpointID": "506ebeae833115993729b4d014717492748d6fafc493039c9d269efb443ff9a1",
                "MacAddress": "ca:34:f4:3a:d6:65",
                "IPv4Address": "172.18.0.2/16",
                "IPv6Address": ""
            }
        },
        "Options": {},
        "Labels": {
            "com.docker.compose.config-hash": "4e5489a9a220a2e16c0f062dbe81bf60aa7cde660627d737e7669cf3a2f36615",
            "com.docker.compose.network": "inception",
            "com.docker.compose.project": "srcs",
            "com.docker.compose.version": "2.40.3"
        }
    }
]