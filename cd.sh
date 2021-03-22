#cd /mnt/c/Users/vanmo/Desktop/compiler
gcc src/main.c -o sample.out -lusb-1.0
sudo chown root:root sample.out
sudo chmod u+s sample.out
./sample.out