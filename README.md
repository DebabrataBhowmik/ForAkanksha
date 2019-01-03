This is a code set up to create a tree with branches of integers, float and vectors and then make a copy of the tree with some cuts applied

First To create a Mother Root File run :

Root -l RootTree.C

This will create a root file which will contain 3 integers branches, 3 float branches and 1 vector branch with 10 entries.

Now to read this Mother root file and make a Root file with the same tree structure but with the entries which pass some cuts, run :

Root -l

.L Analysis.C

Analysis a

a.Loop()

Please don't hesitate to write to me (debabrata.bhowmik@cern.ch) if you have any question.Thanks.
