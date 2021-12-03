# Visual Studio & Visual Studio Code colorful environment
VS & VSCode dark but colorful settings. Distinguishes member functions, static functions, global functions, member variables, static variables, global variables, macros, preprocessor directives, parameters, operators, etc.

![](https://github.com/zdenyhraz/VSColors/blob/master/pics/colors.PNG?raw=true "colors")

## Color Theme
- Update your Visual Studio Code settings from settings.json
- Download cascadia code font from https://github.com/microsoft/cascadia-code/releases

## Terminal Theme
- sudo apt-get install zsh
- sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
- Install fonts & follow instructions for Visual Studio Code & Windows Terminal: https://github.com/romkatv/powerlevel10k#meslo-nerd-font-patched-for-powerlevel10k Fonts -> Manual font installation
- git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
- ZSH_THEME="powerlevel10k/powerlevel10k" in ~/.zshrc
- p10k configure
- plugins=(git zsh-autosuggestions zsh-syntax-highlighting) in ~/.zshrc
- git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
- git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions

## Windows dev environment
- install WSL
- install Ubuntu via Microsoft Store
- install VSCode WSL extension

## Linux dev environment
- sudo apt update
- sudo apt -y upgrade
- sudo apt -y install build-essential
- sudo apt-get install gdb
- sudo apt -y install clang-format
- git config --global user.email "xxxx@xxx.com"
- git config --global user.name "xxxx"


