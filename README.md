## SMID, Martin, et al. Protection by vaccines and previous infection against the Omicron variant of SARS-CoV-2. The Journal of Infectious Diseases, 2022;, jiac161, https://doi.org/10.1093/infdis/jiac161

This repo contains a software code used for delivering the aformentioned article. 

 
### Preparation 

```
cd Vyvanuti
mkdir data
cd data
mkdir temp
cd ..
cd convertool
git clone https://github.com/cyberklezmer/orpp
mkdir bin
cd bin
cmake .. 
make
cd ..
cd ..
cd convertool27
.. (do the same as with convertool)
cd convertool24erratum
.. (do the same as with convertool)

```


### Creating Supplementary Material 2
```
cd Vyvanuti
./batch_delta
./batch_omicron
./batch_logreg
cd report
pdflatex report.tex
```
The input data have to be present at 
```
repository root/data/data_20220215.csv
```
The source data (version as of comes from 15 Feb 2022) is avalable upon approval of Institute of Health information and Statistics of the Czech Republic (https://www.uzis.cz/). 

Typically each batch takes several hours and large RAM (more than 16GB) is needed. R as well as some of its packages are required (see the respective R scripts for the definite list). All resulting files for each model run can be found in **Vyvanuti/outputs/ANALYSISNAME**. 

### Commit history

"Project repo, ready for publication" - the version committed at the time of publication (Feb, 2022)

"Adjust for different preprocessor version" - committed in July, 2022, to perfectly replicate the graphs from Suppl. Mat. 2 (this material has been produced using two different versions of the preprecessor, which the initial commit did not take into account)
