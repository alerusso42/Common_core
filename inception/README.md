his project has been created as part
of the 42 curriculum by alerusso.
/*************************************************/
Description
- explain the use of Docker and the sources
included in the project.
	Docker is a virtualization tool, that has two main purposes:
	1:	significantly lighter than a VM (use the kernel host)
	2:	allows users to test a program without worrying about install all external libraries and binaries: they just download the docker image and launch it as a container.
	It has two main components:
	1:	dockerd (docker daemon): a long running process, that execute
		docker commands;
	2:	dockerCLI (docker client): when the user prompts a docker command in
		bash, a dockerCLI process is created. It communicates with dockerd.
	
##EXAMPLE
	Let's say I want to run minishell in a container.
	I create a Dockerfile
	##CONTINUA...
	It is used using shell commands and three OPTIONAL settings file:
	-	Dockerfile (set up containers);
	-	docker-compose.yml (set up docker environment)
	-	dockerignore (similar to gitignore, but for docker)

- main design choices
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
- comparison between:
◦ Virtual Machines vs Docker
◦ Secrets vs Environment Variables
◦ Docker Network vs Host Network
◦ Docker Volumes vs Bind Mounts

/*************************************************/
Instructions

/*************************************************/
Resources

/*************************************************/
Addictional stuff