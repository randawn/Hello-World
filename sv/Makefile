
EXE       =vcs
VCS_OPT   =+v2k -debug -sverilog -full64
NOVAS_PLI =-P /home/ran/EDA/synopsys/verdi/share/PLI/VCS/LINUX64/novas.tab /home/ran/EDA/synopsys/verdi/share/PLI/VCS/LINUX64/pli.a
FILE      =-f f.lst

all:
	${EXE} ${VCS_OPT} ${NOVAS_PLI} ${FILE}

clean:
	rm ./simv ./simv.daidir/ csrc/ dump.fsdb novas_dump.log ucli.key verdiLog/ novas.rc novas.conf -rf

