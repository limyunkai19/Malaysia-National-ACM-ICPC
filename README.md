# Malaysia National ACM ICPC
An archive of ACM-ICPC Malaysia National al-Khawarizmi Programming Contest in the format of CMS Contest.


# CMS Setup Guide

## Clone This Repository
```bash
git clone https://github.com/limyunkai19/Malaysia-National-ACM-ICPC.git
```

## Setting up CMS
### Install CMS
On **Ubuntu 16.04 LTS** with **CMS 1.3**. Summary of [documentation](https://cms.readthedocs.io/en/v1.3/Installation.html).

```bash
# dependencies
sudo apt-get install -y build-essential openjdk-8-jre openjdk-8-jdk fpc \
    postgresql postgresql-client gettext python2.7 \
    iso-codes shared-mime-info stl-manual cgroup-lite libcap-dev
sudo apt-get install -y python-dev libpq-dev libcups2-dev libyaml-dev \
    libffi-dev python-pip
sudo apt-get install -y nginx-full php7.0-cli php7.0-fpm phppgadmin \
    texlive-latex-base a2ps gcj-jdk haskell-platform
sudo apt-get install -y virtualenv

# if nginx installation fail, you might need to stop and disable apache service
sudo systemctl stop apache2.service
sudo systemctl disable apache2.service
sudo apt-get install nginx-full

# get CMS
wget https://github.com/cms-dev/cms/releases/download/v1.3.1/v1.3.1.tar.gz
tar xvzf v1.3.1.tar.gz
cd cms

# install CMS
sudo ./prerequisites.py install # answer Y for adding to cmsuser group

# install Python dependencies
export LC_ALL="en_US.UTF-8"
export LC_CTYPE="en_US.UTF-8"
virtualenv -p python2 ~/cms_venv
source ~/cms_venv/bin/activate
pip install -r requirements.txt
python setup.py install
```
Logout and login again to make changes (on groups) effective.

### Configure CMS
Summary of [documentation](https://cms.readthedocs.io/en/v1.3/Running%20CMS.html).

The configurations below are for practicing and training purpose. For real contest, you may need to configure extra security settings like non-trivial username and password for ranking server, non-default `secret_key` and etc.

**Configure CMS**
```bash
source ~/cms_venv/bin/activate

cd cms/config
cp cms.conf.sample cms.conf
cp cms.ranking.conf.sample cms.ranking.conf

nano cms.conf
# modify database connection with cmsuser_password
# listen only to 127.0.0.1 address
# number of proxies used = 1

nano cms.ranking.conf
# listen only to 127.0.0.1

cd ..
sudo ./prerequisites.py install
# answer Y to overwrite configurations
```

**Configure Database**

When prompted for password use the same password as `cmsuser_password` above.
```bash
sudo su - postgres
createuser --username=postgres --pwprompt cmsuser
createdb --username=postgres --owner=cmsuser cmsdb
psql --username=postgres --dbname=cmsdb --command='ALTER SCHEMA public OWNER TO cmsuser'
psql --username=postgres --dbname=cmsdb --command='GRANT SELECT ON pg_largeobject TO cmsuser'
exit

cmsInitDB
```

**Add CMS Admin**
```bash
cmsAddUser "" "Admin" "Admin"
cmsAddAdmin -p admin_password admin
```

### Configure Nginx Reverse Proxy
Make changes on `Malaysia-National-ACM-ICPC/nginx_conf/cms` file. If you have a domain name, replace `your_domain` with your domain name. If you don't have a domain name, make Nginx to listen at specific port, remove server name and access your server using the port. Then, apply the configuration.

```bash
nano ~/Malaysia-National-ACM-ICPC/nginx_conf/cms
sudo cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.bak
sudo cp ~/Malaysia-National-ACM-ICPC/nginx_conf/default /etc/nginx/sites-available/
sudo cp ~/Malaysia-National-ACM-ICPC/nginx_conf/cms /etc/nginx/sites-available/
sudo ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/
sudo ln -s /etc/nginx/sites-available/cms /etc/nginx/sites-enabled/
sudo systemctl reload nginx
```

## Setup Contest
### Import Contests and Users
```bash
cd ~/Malaysia-National-ACM-ICPC/

# import contest
cmsImportContest -i year

# import users to contest
python users_add.py users.txt
```
**Note:** You may also add user using the admin interface.


## Run Contest
```bash
cmsLogService 0 &
cmsRankingWebServer --drop
cmsRankingWebServer &
cmsResourceService -a

# remember to switch the job to bg, then disown before logout
disown -a
exit
```

## To Do
- [x] use symlink to reduce the file size
- [ ] research open pdf in new tab. https://github.com/cms-dev/cms/issues/859
