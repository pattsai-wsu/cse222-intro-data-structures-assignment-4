COMPILEFLAGS=
CCOMP=gcc

main: main.o databaseHandler.o add.o lnr.o nlr.o lrn.o  search.o lnrSearch.o delete.o getLargestLeft.o height.o balance.o max.o freeTree.o
	$(CCOMP) $(COMPILEFLAGS) -o plate main.o databaseHandler.o add.o lnr.o nlr.o lrn.o search.o lnrSearch.o delete.o getLargestLeft.o height.o balance.o max.o freeTree.o
main.o: main.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c main.c
databaseHandler.o: databaseHandler.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c databaseHandler.c
add.o: add.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c add.c
lnr.o: lnr.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c lnr.c
nlr.o: nlr.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c nlr.c
lrn.o: lrn.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c lrn.c
search.o: search.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c search.c
lnrSearch.o: lnrSearch.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c lnrSearch.c
delete.o: delete.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c delete.c
getLargestLeft.o: getLargestLeft.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c getLargestLeft.c
height.o: height.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c height.c
balance.o: balance.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c balance.c
max.o: max.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c max.c
freeTree.o: freeTree.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c freeTree.c
clean:
	rm main.o databaseHandler.o add.o lnr.o nlr.o lrn.o search.o lnrSearch.o delete.o getLargestLeft.o height.o balance.o max.o freeTree.o plate
