

source ~/.alias

bindkey -b C-W backward-delete-word

setenv LSCOLORS ExGxFxdxCxegedabagExEx
setenv CLICOLOR yes
set autoexpand
set autolist

set prompt = "%U%n%u:%B%c%b%#"
setenv PATH .:/home/ran:$PATH

# SYNOPSYS
setenv SYNOPSYS "/home/ran/EDA/synopsys"
#setenv LD_LIBRARY_PATH "/lib":"/lib32":"/lib64":"/usr/lib":"/usr/lib32":$LD_LIBRARY_PATH
setenv LD_LIBRARY_PATH "/lib":"/lib32":"/lib64":"/usr/lib":"/usr/lib32":"/usr/lib/x86_64-linux-gnu"
setenv LD_LIBRARY_PATH "/home/ran/EDA/synopsys/verdi/share/PLI/lib/LINUXAMD64":$LD_LIBRARY_PATH
setenv LD_LIBRARY_PATH "/home/ran/EDA/synopsys/verdi/share/PLI/lib/LINUX":$LD_LIBRARY_PATH
setenv LD_LIBRARY_PATH "/home/ran/EDA/synopsys/verdi/share/PLI/lib/LINUX64":$LD_LIBRARY_PATH

# lmgrd
setenv PATH "/home/ran/EDA/synopsys/scl/amd64/bin":$PATH
alias lmlic "lmgrd -c /home/ran/EDA/synopsys/license/synopsys.dat -l lic.log"
setenv SNPSLMD_LICENSE_FILE "27000@ubuntu"
setenv LM_LICENSE_FILE "/home/ran/EDA/synopsys/license/synopsys.dat"

# vcs mx
setenv VCS_ARCH_OVERRIDE linux
setenv VCS_HOME "/home/ran/EDA/synopsys/vcs"
setenv PATH "$VCS_HOME/bin":$PATH

# verdi
setenv VERDI_HOME "/home/ran/EDA/synopsys/verdi"
setenv PATH "$VERDI_HOME/bin":$PATH

# mips
setenv PATH "/home/ran/Hello-world/openMIPS/mips-4.3/bin":$PATH

