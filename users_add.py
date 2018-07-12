import os, argparse
from cms.db import ask_for_contest

parser = argparse.ArgumentParser(description='Add user')
parser.add_argument('users', help='path to the users.txt')
args = parser.parse_args()

contest_id = ask_for_contest()

with open(args.users, 'r') as f:
    users = f.read().split("\n")

for u in users:
    u = u.strip()
    if len(u) == 0:
        continue
    if " " in u:
        user, password = u.split()
    else:
        user, password = u, u

    print "Add user {} with password {}".format(user, password)
    os.system("cmsAddUser '' {} {} &>/dev/null".format(user, user))
    os.system("cmsAddParticipation -c {} -p {} {} &>/dev/null".format(contest_id, user, password))
