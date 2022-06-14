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
rm -r bin (only if bin exists)
mkdir bin
cd bin
cmake .. 
make 
```


### Running the analyses
```
cd Vyvanuti
./batch_delta
./batch_omicron
./batch_logreg
```
The input data have to be present at 
```
../../../bisop_bi/data/data.csv'
```
relatively from **Vyvanuti**. This path may be changed in the above batches. The source data file is avalable upon approval of Institute of Health information and Statistics of the Czech Republic (https://www.uzis.cz/). 

Typically each batch takes several hours. R as well as some of its packages are required (see the respective R scripts for the definite list). All resulting files for each model run can be found in **Vyvanuti/outputs/ANALYSISNAME**. 
