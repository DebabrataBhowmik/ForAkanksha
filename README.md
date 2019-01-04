This is a code set up to create a tree with branches of integers, float and vectors and then make a copy of the tree with some cuts applied

First To create a Mother Root File run :

Root -l RootTree.C

This will create a root file(OriginalTree.root) which will contain 3 integers branches, 3 float branches and 1 vector branch with 10 entries.

Now to read this Mother root file and make a Root file with the same tree structure but with the entries which pass some cuts, run :

Root -l

.L Analysis.C

Analysis a

a.Loop()

You will get a root file named NewFile.root with same tree structure but only 8 entries with it. As, a cut on i2>4 is applied, it has thrown 2 events from the mother tree.


=================================More Information=========================================


Now, if you want to know how Analysis.h, Analysis.C and the branches in Analysis.C came from, then the answer from MakeClass(). You can get this by doing the following : 

Root -l OriginalTree.root

.ls

t1->MakeClass("MyAnalysis")

This will create two files namely, MyAnalysis.h and MyAnalysis.C. If you now open the MyAnalysis.h you can clearly see the branches specified.

Please don't hesitate to write to me (debabrata.bhowmik@cern.ch) if you have any question.Thanks.
