#ANCHOR install node
FROM node
#ANCHOR set environment
ENV MONGO_DB_USERNAME=admin \
	MONGO_DB_PWD=password
#ANCHOR prepare files
RUN mkdir -p /home/app
COPY . /home/app

#ANCHOR start app with
CMD ["node", "/home/app/app/server.js"]