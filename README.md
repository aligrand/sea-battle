
[![Available_in](https://img.shields.io/badge/-Available%20in-555)]()
[![Windows](https://img.shields.io/badge/-WINDOWS-blue)](https://www.microsoft.com/en-us/windows)
[![Linux](https://img.shields.io/badge/-LINUX-blue)]()



[![Requirements](https://img.shields.io/badge/Requirements-gcc%20%2F%20git-blue)]()



# sea-battle
simple classic sea-battle with c in command line environment

# Requirements
* GCC (Mingw)
* git

# installation
first, clone the repository

    git clone https://github.com/khodekhadem/sea-battle

then, move to the directory

    cd sea-battle

compile the sources

    gcc -Wall sb_globdef.h s* -o seabattle
  
# run
use this command

    ./seabattle

# online gaming
for online gaming you have three options, using docker or config your  linux server with my ansible playbook or setup an ftp server on a device

1.DOCKER

1.1 you can cd to docker directory and make your container with these commands
    
    cd docker
    docker compose up
    
1.2 if you want to get into the container and change configurations, i recommend you to use my Dockerfile to build your image
    
    cd docker
    docker build -t vsftpim ./
and run it with
      
    docker run -d -p 20:20 -p 21:21 -p 21100-21110:21100-21110 \
    -e FTP_USER=ansible -e FTP_PASS=ansible1234 \
    -e PASV_ADDRESS=127.0.0.1 -e PASV_MIN_PORT=21100 -e PASV_MAX_PORT=21110 \
    --name vsftpd  --restart=always fauria/vsftpd

2.ANSIBLE

you can config your linux server with my ansible playbook , edit ansible/hosts with your server ip and use this command to copy file to /etc/ansible/hosts

    cd ansible

    cp hosts /etc/ansible/hosts

now you can run my ansible playbook with this command
   
    ansible-playbook ftp.yml

your server will be configed automatically 

3.ftp server

for this we recommend use your android device and install a ftp server app
on it. another notice if you don't want to use your android device as ftp server you must use a __linux__
device for ftp server.

after setting up your server, you have to edit  ftp-download, ftp-upload, WINftp-download.txt and WINftp-upload.txt in ftpc directory.<br>
__in case 1 & 2:__ remmember if you havent changed my config files your username will be ansible and your pass will be ansible1234 and your port in 21

before start the game, you have to upload conf_online_data.bin (in name of online_data.bin in ftp server) to your ftp server. for this, you must use below commands.<br><br>
    
   ```
  WINDOWS:
   
  > ftp <ip> <port>
  > <username>
  > <password>
  > put .\conf_online_data.bin ./online_data.bin
  ```
  ```
  LINUX:
   
  $ ftp <ip> <port>
  $ <username>
  $ <password>
  $ put ./conf_online_data.bin ./online_data.bin
  ```
if you use linux , run this command in temrinal

    ls -ltrh /bin | grep pftp
if you dont have any output you should edit seabattle_ftp.c and change
   
    pftp

with

    ftp -p
# Additional Information
This project is an academic(university) project in a two-person group with accounts
1. www.github.com/khodekhadem
2. www.github.com/aligrand


