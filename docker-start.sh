# delete old container if exists, ignore stdout/stderr
docker container rm -f fhnw_pct &>/dev/null
# -it attaches std streams to the container (type exit to exit the container)
# -v maps the host working directory /home/fhnw_pct in the container, such that all files/folder are synced between host/container
# -w changes the working directory of the container to /home/fhnw_pct upon start
# --rm deletes the container after exit
docker run -it -v `pwd`:/mnt/d/Projects/FS21-Projects/pct -w /mnt/d/Projects/FS21-Projects/pct --name fhnw_pct --rm fhnw_pct bash