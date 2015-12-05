# SPO600-Build-Framework

## Current Status
- [x] **Config**
- [x] **Parser**
- [x] **Permutation**
- [x] **Build**
- [x] **Test script**
- [ ] **Test plugin**
- [x] **Benchmark script**
- [ ] **Benchmark plugin**
- [x] **Analysis**

## Who's Doing What 

The driver for each piece is in **bold**. Please don't be confined by this list -- contribute to any section as you see fit.

0. Config file format - **Miguel**, Andy, Shirwa
0. Initial option lists for config file - **James**, Andy
0. Config file parser - **Gaurav**, Miguel, Shirwa
0. Permute test cases - **Ramanan**, Donald, Han
0. Build - **Yehoshua**, Jayme, Nitish, Joel
0. Test (Sanity Check/Successful Build Test) - **Nitish**, Dmytro, Ramanan
0. Benchmark - **Jayme**, Yehoshua, Nitish
0. Analysis tools/reporting - **Kirill**, Gaurav
0. Code wrangler/git repo maintainer/QA - **Joel**, Jayme, James
0. Inter-module API Coordination - **Donald**, Kirill, Dmytro
0. Top-level bash script - **Chris Tyler**

## API Specifications

    config file -> name of package write to file (analys.txt) for benchmark 

    parse config  -> one group per line, options delimited by "|" (STDOUT) 

    permute options  -> one permutation per line (STDOUT) + ID of groups and group itself to analys.txt 

    build  -> status code and location of start up script + build time, memory used, load of CPU (or it can be called in main) and status code to analys.txt 

    test  -> status code + status code to analys.txt

analys.txt -> benchmark -> SQL Database

Basically, analys.txt would look like this:

    <pck name>

      ID1 of group of options + options
      
      ID1 + build time, memory, CPU load, status code of build
      
      ID1 + status code of test
      
      ID2 +options
      
      ID2 + build time, memory, CPU, status code of build
      
      etc

    <pck name 2>

      ID1
  
      etc
      
Example:

    <apache2.2.31>
      ID1 -fbuiltin -falign-loops -fforward-propagade -fipa-cp
      30s , 125MB , 4% , 0
      0
      ID2 -O2 -fnobuiltin -fnoalign-loops
      37s , 129MB , 7% , 0
      0
    <apache2.4.16>
      ID1 -fbuiltin -falign-loops -fforward-propagade -fipa-cp
      39s , 151MB , 5% , 0
      0
      ID2 -O2 -fnobuiltin -fnoalign-loops
      43s , 172MB , 8% , 0
      0


ID can be used just once - in this case it can be like a delimiter tat separates groups of options.
This is just a draft.


## Instructions for Submitting a Pull Request
0. Create a Github account.
0. Navigate to the project repo by the link above.
0. In the top right of the page make sure that you are "Watching" the repo: https://i.gyazo.com/f887e6199af0f73453556ca0e96dc2bb.png
0. Click the Fork button.
0. This should create a your own version of the repo.
0. Clone the newly forked repo and begin adding your additions/changes. https://help.github.com/articles/cloning-a-repository/
0. Once you have committed and pushed your changes to your own repo, submit a Pull Request, by clicking on the link on the right side of the repo page.
0. Click New Pull Request.
0. Click Create Pull Request, and add any comments about the pull request that you would like the Code Wranglers to know about (be descriptive about what is going on in your submission).
0. The Code Wranglers will manage all pull requests and comment on any that might conflict with the main repo.
0. If you are still having trouble, GitHub's Using pull requests article might be helpful also.
