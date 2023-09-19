:: Install ROS2 on Ubuntu 22.04.3 LTS
:: sudo = Super User Do -> Action d'un super utilisateur

sudo apt update -y
sudo apt upgrade -y
sudo reboot now
locale
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
locale
sudo apt install software-properties-common curl gnupg lsb-release
sudo apt update -y
apt list --upgradable
sudo apt upgrade -y

sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null 1795 sudo apt update
sudo apt upgrade
sudo apt install ros-humble-desktop


:: Pour les IPs

:: ip a 
:: ping 192.168.0.101
:: ip a
:: ping 192.168.0.101
:: ssh nicolas@192.168.0.101
:: history
