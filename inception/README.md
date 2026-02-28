*This project has been created as part of the 42 curriculum by alerusso.*

# Inception

## Description

This project aims to deploy a multi-service infrastructure using Docker.
NOTION: https://www.notion.so/odoacr3e/Inception-27ee699f982b80e88a45f335f662c629
(I contributed in some parts of this notion documentation)

The objective is to:
- Understand containerization concepts
- Deploy multiple services using Docker
- Manage networking, volumes, and secrets securely
- Automate deployment using Docker Compose
- Understand how nginx, wordpress and mariadb must be set.

This project demonstrates how to isolate services that communicate with each other.

## Project Architecture

The infrastructure is built using **Docker containers**, orchestrated with `docker-compose`.

	The goal is to create a site on wordpress, using
	nginx as a web server, mariadb as a database.
	They need to be run inside docker, in three different 
	containers.
	This should be the final result:
	Computer HOST (real)
______________________________________________________
	Computer HOST (VM)						www(443)  |
	____________________________________________|___  |
	|Docker Network								|	| |
	|											|	| |
	| CONTAINER			CONTAINER		   CONTAINER| |
	|  MARIADB--(3306)--WORDPRESS--(9000)--NGINX	| |
	|	  |					|				/		| |
	|	  |					|			   /		| |
	|	  |					|			  /			| |
	|	  |					|___________ /			| |
	|_____|_________________|_______________________| |
		MariaDb			WordPress					  |
______________________________________________________|
	Explaination line per line:
	15: The project must be run on a VM.
		The final binary should run on the port 443 using ssl.
	17:	A docker network must be created. It must the container
		that run the site.

### Services Included
- NGINX (reverse proxy)
- WordPress (application)
- MariaDB (database)

Each service runs inside its own container and communicates through a dedicated Docker network.

## Use of Docker

Docker is used to:
- Containerize each service
- Ensure portability across environments
- Isolate services
- Manage dependencies efficiently
- Simplify deployment

Instead of installing services directly on a system or using full virtual machines, Docker containers provide lightweight, reproducible environments.

## Main Design Choices

- One container per service
- Custom Dockerfiles (no prebuilt images when required)
- Dedicated Docker network
- Use of Docker volumes for persistent data
- Secure handling of credentials via .env
- Reverse proxy configuration with SSL

## Technical Comparisons

### Virtual Machines vs Docker

| Virtual Machines      | Docker                |
|-----------------------|-----------------------|
| Include full OS       | Share host OS kernel  |
| Heavy resource usage  | Lightweight           |
| Slower boot time      | Fast startup          |
| Larger disk size      | Small footprint       |
| Have their own kernel | Share the same kernel |

### Secrets vs Environment Variables

| Secrets                       | Environment Variables             |
|-------------------------------|-----------------------------------|
| Stored securely               | Stored in plain text              |
| Not visible in container logs | Can be exposed                    |
| Designed for sensitive data   | Suitable for non-sensitive config |

Secrets were used for database passwords and sensitive credentials to improve security.

### Docker Network vs Host Network

| Docker Network            | Host Network          |
|---------------------------|-----------------------|
| Isolated                  | Shares host network   |
| Internal DNS resolution   | No isolation          |
| More secure               | Less secure           |

A custom Docker network was used to ensure proper isolation and service name resolution.

### Docker Volumes vs Bind Mounts

| Docker Volumes    | Bind Mounts               |
|-------------------|---------------------------|
| Managed by Docker | Linked to host filesystem |
| Portable          | Host-dependent            |
| More secure       | Less isolated             |

Docker volumes were chosen for persistent database and application data.

## Instructions

all: 	up
daemon: up using a daemon process
stop:	shuts down all containers
clean:	stop
fclean: stop and removes volumes
re: 	fclean daemon
logs:	print containers log
		USAGE: make logs cont="container name"/cont=all
exec:	run the /bin/bash command inside a running container 
		USAGE: make exec cont="container name"/cont=all

### Requirements

- Docker
- Docker Compose
- Make

## Docker network

### docker network types

+-------------------+
| default bridge    | <- container-to-container communication with internal DNS
|                   |    (only within the same bridge)
+-------------------+

+-------------------+
| host              | <- container uses host network, no NAT
+-------------------+

+-------------------+
| overlay           | <- multi-host (swarm), communicates containers on different hosts
+-------------------+

+-------------------+
| none              | <- isolated container, no network interface
+-------------------+

### Layer Meaning

container network	Stack of virtual interfaces inside the container
Docker network	Logical layer created by Docker (bridge, overlay) that connects containers
host network	Container shares the host’s network stack (no NAT, same IP and ports)
layers example

host eth0: 192.168.1.10
+-----------------------------------+
| bridge network (docker0)          |
| 172.17.0.0/16                     |
| container1: 172.17.0.2             |
| container2: 172.17.0.3             |
+-----------------------------------+

### DNS

DNS TABLE: container-name <-> container-ip in docker network
to connect to container2 from container1:
I can do:
curl 172.17.0.3:PORT
Or:
curl container2:PORT