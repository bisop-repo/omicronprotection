#include "tooltools.hpp"

//char* testfilename = "/home/martin/tmp/part/xaa.big.csv";

char testfilename[] = "/home/martin/tmp/part/xaa big.csv";

bool amihome()
{
    ifstream s(testfilename);
    if(!s)
        return false;
    else
        return true;
}

bool testrun = amihome();



string malestr = "M";
string femalestr = "Z";

enum eagegroups { v0011, v1215, v1617, v1824, v2529, v3034, v3539, v4044,v4549, v5055,v5559, v6054,v6559, v7074,v7579, v80plus, enumagegroups };

constexpr unsigned lastage = 100;

unsigned ofage(unsigned age, bool male)
{
    assert(age <= lastage);
    static vector<unsigned> men={	56184,	57721,	58620,	59204,	58715,	58015,	57740,	56280,	56750,	56713,	61914,	62379,	63362,	60919,	56421,	53264,	51083,	49198,	49326,	49136,	49192,	48015,	48911,	49432,	50236,	53764,	59306,	66906,	67898,	72307,	72891,	72248,	74715,	74787,	75882,	77256,	77480,	77352,	78619,	78945,	83571,	91325,	93768,	94694,	97104,	98124,	99110,	93088,	83869,	78778,	75278,	72227,	68280,	68130,	68251,	70531,	73280,	69855,	62426,	60113,	58656,	57135,	60388,	63752,	64833,	64403,	63327,	62643,	62086,	60555,	58253,	54990,	55353,	54972,	50609,	38391,	38781,	35853,	30110,	26969,	24818,	19992,	17455,	14818,	13105,	11760,	10190,	8809,	7654,	6346,	5096,	3671,	2730,	1953,	1334,	863,	560,	382,	236,	136,	248	};
    static vector<unsigned> women={	53869,	54834,	56119,	56310,	55686,	55057,	54864,	53561,	54130,	53847,	58699,	59894,	60370,	58389,	53175,	50588,	48130,	46605,	46618,	46502,	45854,	45606,	46222,	46963,	47479,	50532,	56171,	62938,	63559,	67544,	68882,	68332,	71021,	69633,	70540,	72040,	71929,	72113,	73703,	73873,	77506,	85607,	88414,	89605,	91727,	93566,	93985,	87419,	79608,	75039,	72079,	68879,	65722,	65665,	66572,	68845,	71753,	69507,	62469,	60954,	59273,	58705,	63823,	68173,	70727,	71220,	71504,	71464,	72435,	72781,	70628,	68221,	69175,	71215,	67761,	53993,	55037,	51902,	44718,	41447,	38966,	33294,	30126,	26848,	24715,	22525,	20809,	18726,	17152,	14519,	12342,	9447,	7467,	5586,	4185,	2921,	2131,	1521,	910,	583,	597	};
    assert(men.size()==lastage+1);
    assert(women.size()==lastage+1);
    return male ? men[age] : women[age];
}

string grouplabel(unsigned vk)
{
    static vector<string> g{"0-11", "12-15","16-17","18-24","25-29","30-34","35-39",
    "_40-44","45-49","50-54","55-59","60-64","65-69","70-74","75-79","80+"};
    assert(vk<g.size());
    return g[vk];
}

enum eseverity { enotsevereorunknown, esymptoms, ehospital, enumseverities };


string severitylabel(eseverity s)
{
    switch(s)
    {
    case enotsevereorunknown:
        return "_no_or_unknown_severity";
        break;
    case esymptoms:
        return "symptoms";
        break;
    case ehospital:
        return "hospitalized";
        break;
    default:
        throw "unknown severity";
    }
}

string age2group(unsigned age)
{
    static vector<string> g = {		"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"0-11",	"12-15",	"12-15",	"12-15",	"12-15",	"16-17",	"16-17",	"18-24",	"18-24",	"18-24",	"18-24",	"18-24",	"18-24",	"18-24",	"25-29",	"25-29",	"25-29",	"25-29",	"25-29",	"30-34",	"30-34",	"30-34",	"30-34",	"30-34",	"35-39",	"35-39",	"35-39",	"35-39",	"35-39",	"_40-44",	"_40-44",	"_40-44",	"_40-44",	"_40-44",	"45-49",	"45-49",	"45-49",	"45-49",	"45-49",	"50-54",	"50-54",	"50-54",	"50-54",	"50-54",	"55-59",	"55-59",	"55-59",	"55-59",	"55-59",	"60-64",	"60-64",	"60-64",	"60-64",	"60-64",	"65-69",	"65-69",	"65-69",	"65-69",	"65-69",	"70-74",	"70-74",	"70-74",	"70-74",	"70-74",	"75-79",	"75-79",	"75-79",	"75-79",	"75-79",	"80+"	};
    if(age >= g.size())
       return g[g.size()-1];
    else
       return g[age];
}

string fourage2group(unsigned age)
{
    if(age < 25)
        return "0-24";
    else if(age < 40)
        return "25-39";
    else if(age < 65)
        return "_40-64";
    else
        return "65+";
}


unsigned age2groupnum(unsigned age)
{
    static vector<unsigned> v={	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	2,	2,	3,	3,	3,	3,	3,	3,	3,	4,	4,	4,	4,	4,	5,	5,	5,	5,	5,	6,	6,	6,	6,	6,	7,	7,	7,	7,	7,	8,	8,	8,	8,	8,	9,	9,	9,	9,	9,	10,	10,	10,	10,	10,	11,	11,	11,	11,	11,	12,	12,	12,	12,	12,	13,	13,	13,	13,	13,	14,	14,	14,	14,	14,	15	};

    if(age >= v.size())
       return v[v.size()-1];
    else
       return v[age];
}

unsigned fouragegroup(unsigned a)
{
    if(a < 25)
        return 0;
    else if(a < 40)
        return 1;
    else if(a < 65)
        return 2;
    else
        return 3;
}



enum evaccine { ePfizzer, eModerna, eAstra, eJanssen, enumvaccines, eunknownvaccine = enumvaccines };

enum evariant { eunknownvariant, edelta, eomicron, enumvariants };


vector<string> variantlabels = {"","Delta", "Omikron"};

string vaccabr(evaccine v)
{
    switch(v)
    {
        case ePfizzer:
           return "P";
    case eModerna:
        return "M";
    case eAstra:
        return "A";
    case eJanssen:
        return "J";
    default:
        throw "unknown vacine";
    }
}

evaccine vac2vac(const string& vstr )
{
    static vector<string> vaccnames = {"Comirnaty", "SPIKEVAX", "VAXZEVRIA", "COVID-19 Vaccine Janssen"};

    unsigned i = 0;
    for(;i<enumvaccines; i++)
        if(vstr == vaccnames[i])
            break;
    return static_cast<evaccine>(i);
}

enum vaccovariate { eunvacc,
                    ePfirst1, eMfirst1, eAfirst1,
                    ePfirst2plus, eMfirst2plus, eAfirst2plus,
                    eP1, eM1, eA1, eJ1,
                    eP2, eM2, eA2, eJ2,
                    eP3, eM3, eA3, eJ3,
                    eP4, eM4, eA4, eJ4,
                    ePbooster1, eMbooster1,
                    ePbooster2, eMbooster2,
                    enumvacccovs,
//                        eunknownvacccov = enumvacccovs,
                    eunexamined = enumvacccovs,
                    efirstfinal = eP1,
                    };


struct preprocessparams
{
    /// least date possible (others reported as errors
    int zerodate = date2int("2020-01-01");

    /// date after which the discrimination results are taken into account (before
    /// unknown variant is always assumed)
    string discriminationtdatestr = "2021-12-07";

    /// delay after the first, second ant third shot takes effect
    int v1delay = 14;
    int v2delay = 14;
    int v3delay = 7;

    /// lenght of the window after infection within which hospitalization is examined
    /// (after this limit, the subject is censored in h analysis TBD CHECK THIS!!)
    int hosplimit = 15;
    /// if false, then the date of hospitalization is taken as the event, otherwise
    /// it is the date of the corresponding infection
    bool infdateashospdate = false;

    /// same for deaths (ALSO CHECK)
    int deathlimit = 30;
    bool infdateasdeathdate = false;

    /// number of dates past the horzion, after which dates are regarded as errors
    /// (and corresponding record is dropped)
    int baddatethreshold = 30;

    /// time delay during which new positive tests are not regarded as reinfections
    int infectionsgap = 60;

    /// number of the last postinf covariate (0 = not infected, 1 - first ...)
    int maxinfstatus = 4;

    /// duration of 1st  postinf covariate
    int firstcovreinfduration = 13*7;

    /// duration of 2nd ... \p (naxinfstatus-1)-th - postinf covariate (the last one lasts till infty)
    int covreinfduration = 13*7;

    /// tool for determining covlength, DEPRECATED, NOT USED ANYMORE
    inline int reinfduration(unsigned i) { return i ? covreinfduration : firstcovreinfduration; }

    /// durations of the other than the last postvacc covariates
    int regularcovvaccduration = 61;

    /// if true there is only a single partial vacc covariate, otherwise two
    bool singlepartcov = false;

    /// duration of the last partial vaccination covariates
    /// (the first or the second in dependence on \p singlepartcov)
    /// after reaching its end, the sujbect is censored
    int lastpartialcovvaccduration = 61;

    /// number of covariates following full vacc (including the last one)
    int numfinalcovs = 4;

    /// duration of the last full vaccination covariate
    /// - after reaching its end, the sujbect is censored
    int lastfullcovvaccduration = 61;

    /// duration of the last booster vaccination covariate (currently it is always
    /// the second one).
    int lastboostercovvaccduration = 61;

    /// if true then the records with the first postinf (typically being the gap period)
    /// covariate are dropped (as they shold not occur if the event is infection)
    bool excludefirstcovreinfduration = false;

    /// if true then then the records with Immunity value "other" are dropped
    bool excludeotherimmunity = false;

    /// if true then vaccine abbreviations corresponding to the vaccind accompishing
    /// the full vacc are added to the first postboost covariate value
    bool boosterselect = false;

    /// if true, then only four age categories are used instead of the finer division
    bool fourages = false;

    /// if true then columns InfPriorTime,LastVaccTime are added (with _none if the previous event did not happen)
    bool numericprevevents = false;

    /// if true then vaccines are grouped in the VaccStatus field
    bool groupvaccs = false;

    /// if true then Immunity = "others" everywhere "InfPrior=Inf1" (this is because for some rare events,
    /// no events occured for the fresh immunity)
    bool Inf1_Xtoothers = false;

    bool groupinteraccions = false;

    bool eventiso = false;
    bool eventisu = false;

    /// Inputs that should be provided

    /// start of the sutedy (time 0)
    string firstdatestr;

    /// horzion of the study (time T - once hosps are determined by corresponding
    /// infections, only events (infections) hosplimit is taken from T to get new
    /// horizon (so that the fact of hosp could be decided, similarly deaths and deathlimit)
    string lastdatestr;

    /// variant (if examined)
    evariant variant = eomicron;

    /// values of VaccStatus to ignore (to avoid the strange minus infinite restimates when
    /// no event took place)
    vector<vaccovariate> excludevaccovs;

   // fir kast nubzte exckzdśuib (of zero event categories)
    vector<string> postexcludevaccovs;

};

void addto(vector<string>& labels, vector<unsigned>& counts, const string lbl)
{
    for(unsigned i=0; i<labels.size(); i++)
    {
        if(labels[i] == lbl)
        {
            counts[i]++;
            return;
        }
    }
    assert(counts.size());
    counts[counts.size()-1]++;
}


enum o2rmodes { einfections, ereinfections, ehospitals, edeaths, ehospitalsreinf, evariantinf, evarianthosp, evariantdeath, evariantreinf, ecomparison, ehcomparison };

vector<string> mdelabels
= { "infections", "reinfections", "hospitals", "deaths", "deprecated", "variantinf",
    "varianthosp", "variantdeath", "variantreinf", "comparison", "hcomparison" };

void ockodata2R(string input, string output,
                o2rmodes mode,
                unsigned minage, unsigned maxage, unsigned everyn,
                preprocessparams ppp = preprocessparams() ) // rozdelane
{
    assert(ppp.numfinalcovs <= 4);

    vector<evaccine> statesvaccs =
            { eunknownvaccine,
             ePfizzer, eModerna, eAstra,
              ePfizzer, eModerna, eAstra,
              ePfizzer, eModerna, eAstra, eJanssen,
              ePfizzer, eModerna, eAstra, eJanssen,
              ePfizzer, eModerna, eAstra, eJanssen,
              ePfizzer, eModerna, eAstra, eJanssen,
              ePfizzer, eModerna,
              ePfizzer, eModerna
            };


    vector<string> vcovtexts {
        "_novacc",
        "Ppart1", "Mpart1", "Apart1",
        "Ppart2", "Mpart2", "Apart2",
        "Pfull1", "Mfull1", "Afull1", "Jfull1",
        "Pfull2", "Mfull2", "Afull2", "Jfull2",
        "Pfull3", "Mfull3", "Afull3", "Jfull3",
        "Pfull4", "Mfull4", "Afull4", "Jfull4",
        "Pboost1", "Mboost1",
        "Pboost2", "Mboost2"
    };

    vector<string> groupedvcovtexts {
        "_novacc",
        "part1", "part1", "part1",
        "part2", "part2", "part2",
        "full1", "full1", "full1", "full1",
        "full2", "full2", "full2", "full2",
        "full3", "full3", "full3", "full3",
        "full4", "full4", "full4", "full4",
        "boost1", "boost1",
        "boost2", "boost2"
    };


    assert(statesvaccs.size() == enumvacccovs);
    struct acrecord
    {
        unsigned num = 0;
        unsigned added = 0;
        unsigned included = 0;
        unsigned deadbeforecov = 0;
        unsigned deadbeforeother = 0;
        unsigned deadaftercov = 0;
        unsigned deadafterother = 0;
        unsigned infectedbefore = 0;
        unsigned hospbefore = 0;
        unsigned hospafter = 0;
        unsigned infectedafter = 0;
        unsigned firstdoseoftwoshot[enumvaccines] = {0,0,0,0};
        unsigned finished[enumvaccines] = {0,0,0,0};
        unsigned booster[enumvaccines] = {0,0,0,0};
    };

    vector<acrecord> arecs(enumagegroups);


    int firstdate;
    try
    {
        firstdate = date2int(ppp.firstdatestr);
    }
    catch(...)
    {
        cerr << "Error converting first date string " + ppp.firstdatestr;
        throw;
    }

    int discriminationtdate = date2int(ppp.discriminationtdatestr);

    int lastdate;
    try
    {
        lastdate = date2int(ppp.lastdatestr);
    }
    catch(...)
    {
        cerr << "Error converting last date string " + ppp.lastdatestr;
        throw;
    }

    int safetydate = lastdate + ppp.baddatethreshold;



    cout << "Mode " << mdelabels[mode] << endl;

    cout << "Study period: " << ppp.firstdatestr << " to " << ppp.lastdatestr << endl;

    cout << "Age filter: " << minage << "-" << maxage << endl;

    if(everyn > 1)
        cout << "Precessing every " << everyn << "-th" << endl;


    cout << "Writing to " << output << endl;

    ofstream o(output);
    if(!o)
    {
        cerr << "Cannot open " + output << endl;
        throw;
    }

    ofstream oe(output + ".events.csv");
    if(!oe)
    {
        cerr << "Cannot open " + output + ".events.csv" << endl;
        throw;
    }

    ofstream tex(output + ".tex");
    if(!tex)
    {
       cerr << "Cannot open " + output + ".tex" << endl;
       throw;
    }

    ostringstream header;

    header << "Subject,";
    if(mode==ecomparison || mode==ehcomparison)
        header << "Hosp" << ppp.hosplimit << ","
               << "Oxygen" << ppp.hosplimit << ","
               << "ICU" << ppp.hosplimit << ","
               << "DeathByCov" << ppp.deathlimit << ","
               << "Variant,InfPrior,InfPriorSeverity,VaccStatus,Immunity,"
                <<  "Age,AgeGr,Sex";
    else
      header << "T1,T2,Infected,Hospitalized,Oxygen,ICU,DeadByCov,DeadByOther,"
      <<  "VariantInf,VariantHosp,VariantOxygen,VariantICU,VariantDeath"
      <<  ",InfPrior,InfPriorSeverity,VaccStatus,Immunity,"
      <<  "Age,AgeGr,Sex";

    if(ppp.numericprevevents)
        header << ",InfPriorTime,LastVaccTime";

    o << header.str() << endl;
    oe << header.str();


    enum egender { emale, efemale, enumgenders };

    unsigned baddaterecors = 0;
    unsigned inconsistento = 0;
    unsigned hospitalunassigned = 0;
    unsigned noagerecords = 0;
    unsigned nogenderrecords = 0;
    unsigned deadcovbeforestart = 0;
    unsigned deadotherbeforestart = 0;

    enum evaccorder { novacc, firstdose, secdose, booster, enumvaccorders, eunknownvaccorder = enumvaccorders };

    struct vaccrecord {
                      int t = maxint;
                      evaccorder vaccorder = eunknownvaccorder;
                      evaccine vac = eunknownvaccine;
     };


    cout << "Input " << input << endl;
    csv<';'> data(input);

    cout << "Importing from input, total" << data.r()-1 <<
         " records." << endl;

    static vector<string> labels =
    {  "pohlavi","vek","GEO_KrajKod","GEO_ORPKod","DatumPrvnihoPriznakuOKmin","DatumOdberuOKmin","DatumVysledkuOKmin","DatumHlaseniOKmin","KHS_IsolaceDatum","VYL_datum_vyleceni_final","ZEM_datum_umrti_fin","ZEM_umrti_bin","ock_vek","ock_pohlavi","ock_orp_bydliste","prvnidavka","druhadavka","ukoncene_ockovani","extra_davka","OckovaciLatka","OckovaciLatka1","OckovaciLatka2","OckovaciLatka3","nakaza_po_dokonc","vek","vek_kat","pohlavi","kraj_bydliste","kraj_prvni_nemocnice","datum_positivity","zahajeni_hosp","posledni_zaznam","datum_priznaku","datum_odberu","stav_dle_khs","stav_posledni_zaznam","posledni_hosp_zaznam","nejtezsi_stav","tezky_stav","tezky_stav_pocatek","dni_tezky_stav","tezky_stav_posledni","jip","jip_pocatek","dni_jip","jip_posledni","kyslik","kyslik_pocatek","dni_kyslik","kyslik_posledni","upv","upv_pocatek","dni_upv","upv_posledni","ecmo","ecmo_pocatek","dni_ecmo","ecmo_posledni","umrti","datum_umrti","HFNO","HFNO_pocatek","dni_HFNO","HFNO_posledni","DatumHlaseni1","DatumHlaseni2","DatumHlaseni3","DatumPrvnihoPriznaku1","DatumPrvnihoPriznaku2","DatumPrvnihoPriznaku3","DatumOdberu1","DatumOdberu2","DatumOdberu3","DatumVysledku1","DatumVysledku2","DatumVysledku3","zacatek_hosp_reinf","hosp_reinf","zacatek_JIP_reinf","JIP_reinf","DatumUmrtiLPZ","umrti_LPZ","KHS_StavPacienta",	"symptom", "kat",
       "omicron_po_predchozi_bin","delta_po_predchozi_bin" };


    enum elabels {pohlavi,vek,GEO_KrajKod,GEO_ORPKod,DatumPrvnihoPriznakuOKmin,DatumOdberuOKmin,DatumVysledkuOKmin,DatumHlaseniOKmin,KHS_IsolaceDatum,VYL_datum_vyleceni_final,ZEM_datum_umrti_fin,ZEM_umrti_bin,ock_vek,ock_pohlavi,ock_orp_bydliste,prvnidavka,druhadavka,ukoncene_ockovani,extra_davka,OckovaciLatka,OckovaciLatka1,OckovaciLatka2,OckovaciLatka3,nakaza_po_dokonc,vek_h,vek_kat_h,pohlavi_h,kraj_bydliste,kraj_prvni_nemocnice,datum_positivity,zahajeni_hosp,posledni_zaznam,datum_priznaku,datum_odberu,stav_dle_khs,stav_posledni_zaznam,posledni_hosp_zaznam,nejtezsi_stav,tezky_stav,tezky_stav_pocatek,dni_tezky_stav,tezky_stav_posledni,jip,jip_pocatek,dni_jip,jip_posledni,kyslik,kyslik_pocatek,dni_kyslik,kyslik_posledni,upv,upv_pocatek,dni_upv,upv_posledni,ecmo,ecmo_pocatek,dni_ecmo,ecmo_posledni,umrti,datum_umrti,HFNO,HFNO_pocatek,dni_HFNO,HFNO_posledni,DatumHlaseni1,DatumHlaseni2,DatumHlaseni3,DatumPrvnihoPriznaku1,DatumPrvnihoPriznaku2,DatumPrvnihoPriznaku3,DatumOdberu1,DatumOdberu2,DatumOdberu3,DatumVysledku1,DatumVysledku2,DatumVysledku3,zacatek_hosp_reinf,hosp_reinf,zacatek_JIP_reinf,JIP_reinf,DatumUmrtiLPZ,umrti_LPZ, KHS_StavPacienta,	symptom, kat, omicron_po_predchozi_bin,delta_po_predchozi_bin,enumlabels};

    for(unsigned i=0; i<enumlabels; i++)
        oe << "," << labels[i];
    oe << endl;

    bool openerror = false;
    if(data.c(0) != enumlabels)
    {
        cout << "Wrong number of columns. Expected "
             << enumlabels << " found " << data.c(0) << endl;
        openerror = true;
    }
    else
    {
        for(unsigned i=0; i<enumlabels; i++)
        {
            if(data(0,i) != labels[i])
            {
                cout << "Wrong format: " << labels[i]
                     << " expected, " << data(0,i) << " found."
                     << endl;
                openerror = true;
            }
        }
    }

    if(openerror)
    {
        cout << "Expected header is:" << endl;
        for(unsigned i=0; i<enumlabels; i++)
            cout << " " << labels[i];
        cout << endl;
        throw;
    }

    int T = lastdate - firstdate;

    counter do1counter;
    counter do2counter;
    counter v1datecounter;
    counter v2datecounter;
    counter v3datecounter;
    counter ucounter;
    counter hcounter;

    vector<unsigned> men(lastage+1,0);
    vector<unsigned> women(lastage+1,0);

    unsigned i=1;

    unsigned processed = 0;

    unsigned numinfections = 0;
    unsigned numreinfections = 0;
    unsigned numreinfectionsraw = 0;

    unsigned numcensoredbeforestudy = 0;
    unsigned numeventsbeforestudy = 0; // tbd check
    unsigned numcensoredinstudy = 0;
    unsigned numeventsbeinestudy = 0;
    unsigned numsurvivedstudy = 0;

    vector<unsigned> daysincovs(enumvacccovs,0);
    vector<unsigned> numsincovs(enumvacccovs,0);

    cout << "Processing records from input, excluding inconsistend records:" << endl;

    vector<vector<unsigned>> variants(lastdate-ppp.zerodate+1,vector<unsigned>(enumvariants,0));

    vector<string> lbls = {"_noimmunity",
            "boost2-_alone",
            "boost2+_alone",
            "full2-_alone",
            "full2+_alone",
            "inf6-_alone",
            "inf6+_alone",
            "part_alone",
            "inf6-_boost2-",
            "inf6-_boost2+",
            "inf6-_full2-",
            "inf6-_full2+",
            "inf6+_boost2-",
            "inf6+_boost2+",
            "inf6+_full2-",
            "inf6+_full2+",
            "full2+_inf6-",
            "boost2+_inf6-",
            "interactions",
            "other"};

    vector<unsigned> startcnts(lbls.size(),0);
    vector<unsigned> eventcnts(lbls.size(),0);

//tables
    vector<string> inflbls = {
            "_noinf",
            "inf1",
            "inf2",
            "inf3",
            "inf4+",
            "other"};
    vector<unsigned> infstartcnts(inflbls.size(),0);
    vector<unsigned> infeventcnts(inflbls.size(),0);

    vector<string> vacclbls = {"_novacc",
    "Afull1",
    "Afull2",
    "Afull3",
    "Jfull1",
    "Jfull2",
    "Jfull3",
    "Mboost1",
    "Mboost2",
    "Mfull1",
    "Mfull2",
    "Mfull3",
    "Mpart1",
    "Mpart2",
    "Pboost1",
    "Pboost2",
    "Pfull1",
    "Pfull2",
    "Pfull3",
    "Ppart1",
    "Ppart2",
    "other"};
    vector<unsigned> vaccstartcnts(vacclbls.size(),0);
    vector<unsigned> vacceventcnts(vacclbls.size(),0);
//tables-

    for(; i<data.r(); i+= everyn)
    {
        if(data(i,DatumOdberu1) != "" && data(i,DatumOdberu2) != "")
            numreinfectionsraw++;

        string gstr = data(i,pohlavi);
        bool male;
        if(gstr == "")
            gstr = data(i,ock_pohlavi);
        if(gstr == "F")
            gstr = femalestr;
        if(gstr != malestr && gstr != femalestr)
        {
            nogenderrecords++;
            continue;
        }
        else
            male = gstr == malestr;

        string vs = data(i,vek);
        unsigned age;
        if(vs=="")
            vs = data(i,ock_vek);
        if(vs=="")
        {
            noagerecords++;
            continue;
        }
        else
        {
            try
            {
                age = stoul(vs);
                if(age < minage || age > maxage)
                    continue;
            }
            catch (...)
            {
                cout << "Cannot convert age " << vs << "' to unsigned" << endl;
                noagerecords++;
                continue;
            }
         }

        unsigned vknum=age2groupnum(age);
        assert(vknum < enumagegroups);

        assert(vknum < arecs.size());
        acrecord& acr = arecs[vknum];
        acr.num++;

        int truedeathbycovdate = maxint;
        string ddstr = data(i,ZEM_datum_umrti_fin);
        if(ddstr != "") // no death
        {
            int ddabs = date2int(ddstr, ppp.zerodate, safetydate, ucounter);
            if(ddabs==maxint)
            {
                baddaterecors++;
                continue;
            }
            if(ddabs <= lastdate)
            {
                if(ddabs > firstdate)
                   truedeathbycovdate = ddabs - firstdate;
                else
                {
                   deadcovbeforestart++;
                   acr.deadbeforecov++;
                   continue;
                }
            }
        }

        int deathbyotherdate = maxint;
        if(truedeathbycovdate == maxint)
        {
            string dostr = data(i,DatumUmrtiLPZ);
            if(dostr != "") // no death
            {
                int doabs = date2int(dostr, ppp.zerodate, safetydate, ucounter);
                if(doabs==maxint)
                {
                    baddaterecors++;
                    continue;
                }
                if(doabs <= lastdate)
                {
                    if(doabs > firstdate )
                       deathbyotherdate = doabs - firstdate;
                    else
                    {
                       deadotherbeforestart++;
                       acr.deadbeforeother++;
                       continue;
                    }
                }
            }
        }

        bool hospbefore = false;
        struct hosprecord
        {
            enum econdition { enan, eyes, eno };
            int date;
            evariant variant;
            int positivity = maxint;
            econdition oxygen = enan;
            econdition icu = enan;
            int infdateassigned = maxint;
        };
        vector<hosprecord> hosps;



        string hstr = data(i,zahajeni_hosp);
        if(hstr != "") // no hosp
        {
            int habs = date2int(hstr, ppp.zerodate, safetydate, hcounter);
            if(habs==maxint)
            {
                baddaterecors++;
                continue;
            }
            if(habs <= lastdate)
            {
                int positivity = maxint;
                string pstr = data(i,datum_positivity);
                int pabs = date2int(pstr, ppp.zerodate, safetydate, hcounter);
                if(pabs != maxint)
                    positivity = pabs - firstdate;
                hosprecord::econdition oxygen =
                    data(i,ecmo) == "1" || data(i,upv) == "1" || data(i,kyslik) == "1"
                        ? hosprecord::eyes : hosprecord::eno;

                hosprecord::econdition icu =
                    data(i,jip) == "1"
                        ? hosprecord::eyes : hosprecord::eno;

                hosps.push_back({habs - firstdate,eunknownvariant,positivity, oxygen, icu});
                if(habs < firstdate)
                    hospbefore = true;
            }
        }
        string hrstr = data(i,zacatek_hosp_reinf);
        if(hrstr != "") // no hosp
        {
            int habs = date2int(hrstr, ppp.zerodate, safetydate, hcounter);
            if(habs==maxint)
            {
                baddaterecors++;
                continue;
            }
            if(habs <= lastdate)
            {
                int hrel = habs - firstdate;

                if(hosps.size()==0 || abs(hrel-hosps[0].date) > ppp.infectionsgap )
                {
                    hosprecord r = {hrel,eunknownvariant};
                    r.icu = data(i,JIP_reinf) == "1"
                            ? hosprecord::eyes : hosprecord::eno;
                    hosps.push_back(r);
                }
            }
        }

        static constexpr int nohosp = -1;

        struct infrecord
        {
            int t = maxint;
            evariant variant = eunknownvariant;
            eseverity severity;
            int hospindex = nohosp;
        };

        vector<infrecord> infections;

        string okstr = data(i,DatumOdberuOKmin);
        if(okstr != "") // no infection
        {
            string do1str = data(i,DatumOdberu1);
            int do1abs;
            if(do1str == "")
                do1abs = date2int(okstr, ppp.zerodate, safetydate, do1counter);
            else
                do1abs = date2int(do1str, ppp.zerodate, safetydate, do1counter);
            evariant variant1 = eunknownvariant;

            if(do1abs >= discriminationtdate)
            {
                if(data(i,kat) == variantlabels[eomicron] )
                    variant1 = eomicron;
                else if(data(i,kat) == variantlabels[edelta])
                    variant1 = edelta;
            }

            if(do1abs == maxint)
            {
                baddaterecors++;
                continue;
            }


            if(do1abs <= lastdate)
            {
                eseverity s = data(i,symptom) == "1" ? esymptoms : enotsevereorunknown;
                infections.push_back({do1abs - firstdate, variant1,s });
                numinfections++;
                variants[do1abs-ppp.zerodate][variant1]++;
            }

            string do2str = data(i,DatumOdberu2);
            if(do2str != "") // no infection
            {
                int do2abs = date2int(do2str, ppp.zerodate, safetydate, do2counter);

                if(do2abs == maxint)
                {
                    baddaterecors++;
                    continue;
                }

                evariant variant2 = eunknownvariant;
                if(do2abs >= discriminationtdate)
                {
                    if(data(i,omicron_po_predchozi_bin) == "1")
                       variant2 = eomicron;
                    else if(data(i,delta_po_predchozi_bin) == "1")
                        variant2 = edelta;
                    else
                        variant2 = eunknownvariant;
                }

                if(do2abs <= lastdate)
                {
                    infections.push_back( { do2abs - firstdate, variant2 , enotsevereorunknown});
                    numinfections++;
                    numreinfections++;

                    variants[do2abs-ppp.zerodate][variant2]++;
                }
            }
            // tbd third reinfection
        }


        for(unsigned j=0; j<hosps.size(); j++)
if(1)
        {
            bool assigned = false;

            int decisiondate =
                    j == 0 && hosps.size() == 1
                               && hosps[j].positivity != maxint
                    && abs(hosps[j].positivity - hosps[j].date ) < ppp.infectionsgap
                    ? hosps[j].positivity : hosps[j].date;

            for(unsigned k=0; k<infections.size(); k++)
            {
                if(abs(infections[k].t-decisiondate) < ppp.infectionsgap)
                {
                    infections[k].hospindex = j;
                    infections[k].severity = ehospital;
                    hosps[j].variant = infections[k].variant;
                    hosps[j].infdateassigned = infections[k].t;
                    assigned = true;
                    break;
                }
            }

            if(!assigned)
            {
                unsigned k=0;
                auto iter = infections.begin();
                for( ;k<infections.size(); k++, iter++)
                    ;
                if(k == 0
                  || (k > 0 && abs(infections[k-1].t - decisiondate) > ppp.infectionsgap))
                {
                    if(!(k>0 && k< infections.size() && abs(infections[k-1].t - decisiondate) <= ppp.infectionsgap))
                    { // we insert an infection
                        infections.insert(iter,
                           {decisiondate, eunknownvariant,ehospital,
                            static_cast<int>(j) });

                        numinfections++;
                        assigned = true;
                    }

                }
            }
            if(!assigned)
            {
                cout << i << ": date from hosp " << hosps[j].date
                     << " (" << hosps[j].positivity << ")"
                     << " unassigned to infections: ";
                for(unsigned i=0; i<infections.size(); i++)
                     cout << infections[i].t << " ";
                cout << endl;
                hospitalunassigned++;
            }
        }
else         // saving old code
{
    bool assigned = false;

    int decisiondate =
            j == 0 && hosps.size() == 1
                       && hosps[j].positivity != maxint
                        ? hosps[j].positivity : hosps[j].date;

    for(unsigned k=0; k<infections.size(); k++)
    {
        if(abs(infections[k].t-decisiondate) < ppp.infectionsgap)
        {
            infections[k].hospindex = j;
            infections[k].severity = ehospital;
            hosps[j].variant = infections[k].variant;
            hosps[j].infdateassigned = infections[k].t;
            assigned = true;
            break;
        }
    }

    if(!assigned &&
           (infections.size()==0
             || infections[0].t > hosps[j].date + ppp.infectionsgap))
    // tbd hospitals far later than infection....
    {
        evariant variant = eunknownvariant;
        if(hosps[j].date + firstdate >= discriminationtdate)
        {
            if(data(i,kat) == variantlabels[eomicron] )
                variant = eomicron;
            else if(data(i,kat) == variantlabels[edelta])
                variant = edelta;
        }
        infections.insert(infections.begin(),{hosps[j].date, variant,ehospital,
                                              static_cast<int>(j) });
        numinfections++;
        assigned = true;
    }
    if(!assigned)
    {
        cout << i << ": date from hosp " << hosps[j].date
             << " (" << hosps[j].positivity << ")"
             << " unassigned to infections: ";
        for(unsigned i=0; i<infections.size(); i++)
             cout << infections[i].t << " ";
        cout << endl;
        hospitalunassigned++;
    }
}


        // vaccines

        vector<vaccrecord> vaccinations;

        string v1str = data(i,OckovaciLatka1);
        if(v1str != "")
        {
            evaccine v = vac2vac(v1str);
            if(v==eunknownvaccine)
                throw "unknown vaccine " + v1str;

            string v1datestr = data(i,prvnidavka);
            if(v1datestr == "")
            {
                cout << "First shot date missing" << endl;
                inconsistento++;
                continue;
            }

            int v1dateabs = date2int(v1datestr, ppp.zerodate, safetydate, v1datecounter);
            if(v1dateabs == maxint)
            {
                baddaterecors++;
                continue;
            }

            vaccrecord v1;
            v1.t = v1dateabs + ppp.v1delay - firstdate;
            v1.vaccorder = firstdose;
            v1.vac = v;
            vaccinations.push_back(v1);

            string v2str = data(i,OckovaciLatka2);
            if(v2str != "")
            {
                evaccine v = vac2vac(v2str);
                if(v==enumvaccines)
                    throw "unknown vaccine " + v2str;

                string v2datestr = data(i,druhadavka);
                if(v2datestr == "")
                {
                    cout << "Second shot date missing"  << endl;
                    inconsistento++;
                    continue;
                }

                int v2dateabs = date2int(v2datestr, ppp.zerodate,safetydate, v2datecounter);
                if(v2dateabs == maxint)
                {
                    baddaterecors++;
                    continue;
                }

                vaccrecord v2;
                v2.t = v2dateabs + ppp.v2delay - firstdate;
                v2.vaccorder = secdose;
                v2.vac = v;
                vaccinations.push_back(v2);

            }
            string v3str = data(i,OckovaciLatka3);
            if(v3str != "")
            {
                evaccine v = vac2vac(v3str);
                if(v==enumvaccines)
                    throw "unknown vaccine " + v3str;

                string v3datestr = data(i,extra_davka);
                if(v3datestr == "")
                {
                    cout << "Booster date missing" << endl;
                    inconsistento++;
                    continue;
                }

                int v3dateabs = date2int(v3datestr, ppp.zerodate,safetydate, v3datecounter);
                if(v3dateabs == maxint)
                {
                    baddaterecors++;
                    continue;
                }

                vaccrecord v3;
                v3.t = v3dateabs + ppp.v3delay - firstdate;
                v3.vaccorder = booster;

                v3.vac = v;
                vaccinations.push_back(v3);
            }

        }

        infrecord* deadlyinfection = 0;

        if(infections.size())
        {
            bool error = false;
            for(unsigned j=0; j<infections.size()-1; j++)
            {
                if(infections[j].t >= infections[j+1].t)
                {
                    cout << "Wrong ordering of infections" << endl;
                    error = true;
                    break;
                }
            }
            if(error)
            {
                inconsistento++;
                continue;
            }
            for(unsigned j=0; j<infections.size(); j++)
            {
                if(truedeathbycovdate != maxint
                        && truedeathbycovdate >= infections[j].t
                        && truedeathbycovdate < infections[j].t + ppp.deathlimit)
                    deadlyinfection = &(infections[j]);
            }
        }


        if(vaccinations.size())
        {
            bool error = false;
            for(unsigned j=0; j<vaccinations.size()-1; j++)
            {
                if(vaccinations[j].t >= vaccinations[j+1].t)
                {
                    cout << "Wrong ordering of shots " << endl;
                    error = true;
                    break;
                }
            }
            if(error)
            {
                inconsistento++;
                continue;
            }
        }

        acr.included++;
        if(truedeathbycovdate != maxint)
            acr.deadaftercov++;
        if(deathbyotherdate != maxint)
            acr.deadafterother++;
        if(hosps.size())
        {
            if(hospbefore)
                acr.hospbefore++;
            else
                acr.hospafter++;
        }
        for(unsigned j=0; j<infections.size(); j++)
        {
            if(infections[j].t<0)
                acr.infectedbefore++;
            else
                acr.infectedafter++;
        }
        if(vaccinations.size()>0)
        {
            if(vaccinations[0].vac == eJanssen)
                acr.finished[eJanssen]++;
            else
            {
                acr.firstdoseoftwoshot[vaccinations[0].vac]++;
                if(vaccinations.size()>1)
                   acr.finished[vaccinations[1].vac]++;
            }
            if(vaccinations.size()>2)
                acr.booster[vaccinations[2].vac]++;
        }

        if(male)
            men[min(age,lastage)]++;
        else
            women[min(age,lastage)]++;
        string agelabel;
        if(ppp.fourages)
            agelabel = fourage2group(age);
        else
            agelabel = age2group(age);


         int lastinfdate = maxint;
//         eseverity lastinfseverity = enotsevereorunknown;

         unsigned currentvaccstatus=eunvacc;
         int lastvaccstatuschangedate = maxint;

         int t1 = ppp.zerodate - firstdate; // may be negative, I know, I count wizth it

         unsigned nextinfptr = 0;
         unsigned nextvaccptr = 0;

         int enddate = T;

         if((mode == ehospitals || mode == evarianthosp) && ppp.infdateashospdate)
             enddate = min(enddate,T-ppp.hosplimit);

         if((mode == edeaths || mode == evariantdeath) && ppp.infdateasdeathdate)
             enddate = min(enddate,T-ppp.deathlimit);

         enddate = min(min(truedeathbycovdate,deathbyotherdate),enddate);

         if(mode == ereinfections || mode == evariantreinf)
         {
             if(vaccinations.size())
                 enddate = min(vaccinations[0].t,enddate);
         }

         hosprecord *hosp = 0;
         int hospeventdate = maxint;

         if(mode == ehospitals || mode == evarianthosp)
         {
             for(unsigned j=0; j<hosps.size(); j++)
             {
                if(ppp.infdateashospdate)
                {
                    if(hosps[j].infdateassigned > 0
                            && hosps[j].infdateassigned != maxint)
                    {
                        hospeventdate = hosps[j].infdateassigned;
                        hosp = &hosps[j];
                        break;
                    }
                }
                else
                {
                    if(hosps[j].date > 0)
                    {
                        hospeventdate = hosps[j].date;
                        hosp = &hosps[j];
                        break;
                    }
                }
             }
         }

         if((mode == evarianthosp || mode == ehospitals))
             enddate = min(hospeventdate,enddate);

         int currentinfstatus = 0;

         infrecord* lastinfection = 0;
         infrecord* currentinfection = 0;

         int lastvaccdate = maxint;
         int currentvaccdate = maxint;


         for(;;)
         {
             unsigned newinfstatus = currentinfstatus;
             int nextinfdate = maxint;

             for(;nextinfptr < infections.size(); nextinfptr++)
             {
                 if((mode==ehospitals || mode==evarianthosp)
                            && infections[nextinfptr].hospindex != nohosp
                            && infections[nextinfptr].t >= 0) // we have to exclude the infection that cuaset hosp
                     continue;
                 // if infection leading to hosp is event, then it is coded into hospeventdate, similarly deaths
                 nextinfdate = infections[nextinfptr].t;
                 break;
             }

             int nextvaccdate = maxint;
             if(nextvaccptr < vaccinations.size())
                 nextvaccdate = vaccinations[nextvaccptr].t;

             int nextinfstatusupdate;
             if(currentinfstatus == 0 || currentinfstatus == ppp.maxinfstatus)
                 nextinfstatusupdate = maxint;
             else
             {
                nextinfstatusupdate=lastinfdate + ppp.firstcovreinfduration;;
                for(;;)
                {
                    if(nextinfstatusupdate > t1)
                        break;
                    nextinfstatusupdate += ppp.covreinfduration;
                }
             }

             unsigned newvaccstatus = currentvaccstatus;
             int nextvaccstatusdate = maxint;
             unsigned candidatevaccstatus = currentvaccstatus;

             if(currentvaccstatus > eunvacc)
             {
                 assert(lastvaccstatuschangedate < maxint);
                 bool last = false;
                 int dose = 2;

                 switch(currentvaccstatus)
                 {
                     case ePfirst1:
                         last = ppp.singlepartcov;
                         candidatevaccstatus = last ? eunexamined : ePfirst2plus;
                         dose = 1;
                     break;
                     case eMfirst1:
                         last = ppp.singlepartcov;
                         candidatevaccstatus = last ? eunexamined : eMfirst2plus;
                         dose = 1;
                     break;
                     case eAfirst1:
                         last = ppp.singlepartcov;
                         candidatevaccstatus = last ? eunexamined : eAfirst2plus;
                         dose = 1;
                     break;
                     case ePfirst2plus:
                     case eAfirst2plus:
                     case eMfirst2plus:
                         last = true;
                         candidatevaccstatus = eunexamined;
                         dose = 1;
                     break; // no change
                     case eP1:
                         candidatevaccstatus = ppp.numfinalcovs  == 1 ? eunexamined : eP2;
                         last = ppp.numfinalcovs  == 1;
                     break;
                     case eM1:
                         candidatevaccstatus = ppp.numfinalcovs == 1 ? eunexamined : eM2;
                         last = ppp.numfinalcovs  == 1;
                     break;
                     case eA1:
                         candidatevaccstatus = ppp.numfinalcovs == 1 ? eunexamined : eA2;
                         last = ppp.numfinalcovs  == 1;
                     break;
                     case eJ1:
                         candidatevaccstatus = ppp.numfinalcovs == 1 ? eunexamined : eJ2;
                         last = ppp.numfinalcovs  == 1;
                     break;
                     case eP2:
                         candidatevaccstatus = ppp.numfinalcovs == 2 ? eunexamined : eP3;
                         last = ppp.numfinalcovs  == 2;
                     break;
                     case eM2:
                         candidatevaccstatus = ppp.numfinalcovs == 2 ? eunexamined : eM3;
                         last = ppp.numfinalcovs  == 2;
                     break;
                     case eA2:
                         candidatevaccstatus = ppp.numfinalcovs == 2 ? eunexamined : eA3;
                         last = ppp.numfinalcovs  == 2;
                     break;
                     case eJ2:
                         candidatevaccstatus = ppp.numfinalcovs == 2 ? eunexamined : eJ3;
                         last = ppp.numfinalcovs  == 2;
                     break;
                     case eP3:
                         candidatevaccstatus = ppp.numfinalcovs == 3 ? eunexamined : eP4;
                         last = ppp.numfinalcovs  == 3;
                     break;
                     case eM3:
                         candidatevaccstatus = ppp.numfinalcovs == 3 ? eunexamined : eM4;
                         last = ppp.numfinalcovs  == 3;
                     break;
                     case eA3:
                         candidatevaccstatus = ppp.numfinalcovs == 3 ? eunexamined : eA4;
                         last = ppp.numfinalcovs  == 3;
                     break;
                     case eJ3:
                         candidatevaccstatus = ppp.numfinalcovs == 3 ? eunexamined : eJ4;
                         last = ppp.numfinalcovs  == 3;
                     break;
                     case eP4:
                     case eM4:
                     case eA4:
                     case eJ4:
                         last = 3;
                         candidatevaccstatus = eunexamined;
                     break;
                     case ePbooster1:
                         candidatevaccstatus = ePbooster2;
                         dose = 3;
                     break;
                     case eMbooster1:
                          candidatevaccstatus = eMbooster2;
                          dose = 3;
                     break;
                     case ePbooster2:
                     case eMbooster2:
                         last = true;
                         candidatevaccstatus = eunexamined;
                         dose = 3;
                     break;
                     case eunexamined:
                     throw "unexamined";
                     break; // no change
                     default:
                         throw "unknown option";
                 }

                 if(candidatevaccstatus != currentvaccstatus)
                 {
                     nextvaccstatusdate = lastvaccstatuschangedate;
                     if(!last)
                         nextvaccstatusdate += ppp.regularcovvaccduration;
                     else
                     {
                         switch(dose)
                         {
                         case 1:
                             nextvaccstatusdate += ppp.lastpartialcovvaccduration;
                             break;
                         case 2:
                             nextvaccstatusdate += ppp.lastfullcovvaccduration;
                             break;
                         case 3:
                             nextvaccstatusdate += ppp.lastboostercovvaccduration;
                             break;
                         default:
                             throw "unknown dose";
                         }
                     }
                 }
             }

             int t2 = min(nextvaccdate,
                          min(nextinfdate,
                          min(nextvaccstatusdate,
                          min(nextinfstatusupdate,enddate))));

             if(t2==nextvaccstatusdate)
             {
                 lastvaccstatuschangedate = t2;
                 newvaccstatus = candidatevaccstatus;
                 if(newvaccstatus == eunexamined)
                    enddate = min(enddate,nextvaccstatusdate);
                 else if(nextvaccstatusdate > 0)
                    numsincovs[newvaccstatus]++;
             }

             if(t2==nextinfdate
                     && (mode == evariantinf || mode == evariantreinf
                         || mode == ecomparison || mode == ehcomparison)
                     && t2 > 0)
                 enddate = nextinfdate;

             if(t2==nextinfstatusupdate)
                 newinfstatus++;

             if(t2==nextvaccdate)
             {
                 vaccrecord e = vaccinations[nextvaccptr++];
                 assert(e.vaccorder >= firstdose);
                 if(e.vaccorder == firstdose)
                 {
                     assert(currentvaccstatus == novacc);
                     switch(e.vac)
                     {
                     case ePfizzer:
                         newvaccstatus = ePfirst1;
                         break;
                     case eModerna:
                         newvaccstatus = eMfirst1;
                         break;
                     case eAstra:
                         newvaccstatus = eAfirst1;
                         break;
                     case eJanssen:
                         newvaccstatus = eJ1;
                         break;
                     default:
                         throw "unknown vacc";
                     }
                 }
                 else if(e.vaccorder == secdose)
                 {
                     if(e.vac == eJanssen) // can happen by mistake
                     {
                         cout << "Sec dose of Janssen!" << endl;
                         inconsistento++;
                         continue;
                         // tbd should not happen here, give throw instead
                     }
                     switch(e.vac)
                     {
                     case ePfizzer:
                         newvaccstatus = eP1;
                         break;
                     case eModerna:
                         newvaccstatus = eM1;
                         break;
                     case eAstra:
                         newvaccstatus = eA1;
                         break;
                     default:
                         throw "unknown vacc";
                     }
                 }
                 else if(e.vaccorder == booster)
                 {
                     switch(e.vac)
                     {
                     case ePfizzer:
                         newvaccstatus = ePbooster1;
                         break;
                     case eModerna:
                         newvaccstatus = eMbooster1;
                         break;
                     case eAstra: // tbd imho should not happen here
                     case eJanssen:
                         newvaccstatus = eunexamined;
                         break;
                     default:
                         throw "unknown vacc or illegal booster";
                     }

                 }
                 else
                     assert(0);

                 lastvaccstatuschangedate = t2;
                 currentvaccdate = t2;
                 if(newvaccstatus == eunexamined)
                    enddate = min(enddate,nextvaccdate);
                 else if(nextvaccdate > 0)
                    numsincovs[newvaccstatus]++;
             }

             bool event = false;

             int inf;
             int variantinf;
             if(t2 == nextinfdate)
             {
                 newinfstatus = 1;
                 lastinfdate = t2;

                 variantinf = infections[nextinfptr].variant == ppp.variant ? 1 : 0;
                 currentinfection = &(infections[nextinfptr]);

                 nextinfptr++;
                 inf = 1;
                 if(mode == evarianthosp  && !variantinf && t2 > 0)
                     enddate = nextinfdate;
                 // tbd evariantdeath too
             }
             else
             {
                 inf = 0;
                 variantinf = 0;
             }


             if(t2>0)
             {
                 switch(mode)
                 {
                 case einfections:
                     event = inf;
                     break;
                 case evariantreinf:
                 case evariantinf:
                     event = variantinf;
                     break;
                 default:
                     break;
                 }


                 int t1nonneg = max(0,t1);
                 string infpriorstr;
                 if(currentinfstatus == 0)
                     infpriorstr = "_noinf";
                 else
                 {
                     ostringstream os;
                     os << "inf";
                     os << currentinfstatus-1;
                     if(currentinfstatus == ppp.maxinfstatus)
                         os << "+";
                     infpriorstr = os.str();
                 }

                 string boosteradd;
                 if(ppp.boosterselect && (currentvaccstatus==eMbooster1 || currentvaccstatus == ePbooster1
                                      || currentvaccstatus==eMbooster2 || currentvaccstatus == ePbooster2))
                     boosteradd = vaccabr(vaccinations[vaccinations.size()-2].vac);
                 else
                     boosteradd = "";


                 string immunity;
                 const string otherstr = "other";
                 const string alonestr = "alone";
                 const string interstr = "interactions";

                 if(currentinfstatus == 1)
                     immunity = otherstr;
                 else
                 {
                     bool iold = false;
                     string istring;
                     if(currentinfstatus == 0)
                         istring = "";
                     else if(currentinfstatus > 2)
                     {
                         istring = "inf6+";
                         iold = true;
                     }
                     else
                     {
                         istring = "inf6-";
                         iold = false;
                     }

                     if(currentvaccstatus == eunvacc)
                     {
                         if(currentinfstatus == 0)
                             immunity = "_noimmunity";
                         else
                            immunity = istring + "_" + alonestr;
                     }
                     else
                     {
                         string vstring;
                         bool partial = false;
                         switch(currentvaccstatus)
                         {
                         case eP1:
                         case eM1:
                         case eJ1:
                         case eA1:
                             vstring = "full2-";
                             break;
                         case ePfirst1:
                         case eMfirst1:
                         case eAfirst1:
                             vstring = "part"; // "part2-"; quickfix for the paper, should not be lik that
                             partial=true;
                             break;
                         case ePfirst2plus:
                         case eMfirst2plus:
                         case eAfirst2plus:
                             vstring = "part2+";
                             partial=true;
                             break;
                         case ePbooster1:
                         case eMbooster1:
                             vstring = "boost2-";
                             break;
                         case ePbooster2:
                         case eMbooster2:
                             vstring = "boost2+";
                             break;
                         default:
                             vstring = "full2+";
                             break;
                         }
                         if(currentinfstatus == 0)
                             immunity = vstring + "_" + alonestr;
                         else
                         {
                             if(ppp.groupinteraccions)
                                 immunity = interstr;
                             else
                             {
                                 assert(nextvaccptr > 0);
                                 assert(lastinfection);
                                 if(partial)
                                     immunity = otherstr;
                                 else
                                 {
                                     if(lastvaccstatuschangedate < lastinfection->t)
                                     {
                                         if(iold)
                                            immunity = otherstr;
                                         else
                                            immunity = vstring + "_" + istring;
                                     }
                                     else
                                     {
                                         if(ppp.Inf1_Xtoothers && currentinfstatus == 2)
                                             immunity = otherstr;
                                         else
                                            immunity = istring + "_" + vstring;
                                     }
                                 }
                             }
                         }
                     }
                 }

                 if(immunity == "")
                     throw "immunity == 0";

                 string severitystr = severitylabel(
                              lastinfection ? lastinfection->severity
                                            : enotsevereorunknown);


                 bool excludevc = false;
                 for(unsigned j=0; j<ppp.excludevaccovs.size(); j++)
                     if(currentvaccstatus == ppp.excludevaccovs[j])
                     {
                         excludevc = true;
                         break;
                     }

                 bool excluderecord = excludevc
                    || (ppp.excludefirstcovreinfduration && currentinfstatus == 1)
                    || (ppp.excludeotherimmunity && immunity == otherstr);

                 bool dooutput = false;


                 bool uevent = false;
                 bool oevent = false;

                 ostringstream os;

                 if(mode == ecomparison || mode == ehcomparison)
                 {
                     if(inf && currentinfection->variant != eunknownvariant)
                     {
                        if(!excluderecord)
                        {
                            string hospstr = "";
                            string oxygenstr = "";
                            string icustr = "";
                            auto hi = currentinfection->hospindex;
                            if(t2 <= T - ppp.hosplimit)
                            {
                               hospstr = hi != nohosp ? "1" : "0";
                               if(hi != nohosp && hosps[hi].date <=  t2+ppp.hosplimit)
                               {
                                   hosprecord& h = hosps[hi];
                                   switch(h.oxygen)
                                   {
                                   case hosprecord::enan:
                                       break;
                                   case hosprecord::eyes:
                                       oxygenstr = "1";
                                   break;
                                   case hosprecord::eno:
                                       oxygenstr = "0";
                                   break;
                                   }

                                   switch(h.icu)
                                   {
                                   case hosprecord::enan:
                                       break;
                                   case hosprecord::eyes:
                                       icustr = "1";
                                   break;
                                   case hosprecord::eno:
                                       icustr = "0";
                                   break;
                                   }
                               }
                               else
                               {
                                   hospstr = "0";
                                   icustr = "0";
                                   oxygenstr = "0";
                               }
                            }
                            string deathstr = "";
                            if(t2 <= T - ppp.deathlimit)
                                deathstr = truedeathbycovdate <= t2+ppp.deathlimit ? "1" : "0";

                            if(mode == ecomparison || (mode==ehcomparison && hi != nohosp))
                            {
                                dooutput = true;
                                event = hi != nohosp;

                                os << i  << ","
                                   << hospstr << ","
                                   << oxygenstr << ","
                                   << icustr << ","
                                   << deathstr << ","
                                   << variantlabels[currentinfection->variant] << ",";
                            }
                        }
                     }
                 }
                 else
                 {
                     if(!excluderecord)
                     {
                         dooutput = true;
                         os << i << "," << t1nonneg << "," << t2 << ","
                           << inf << ",";

                         string hospstr = "";
                         string oxygenstr = "";
                         string icustr = "";


                         if(mode==ehospitals || mode==evarianthosp)
                         {
                             hospstr = "0";
                             oxygenstr = "0";
                             icustr = "0";

                             if(t2==hospeventdate)
                             {
                                 assert(hosp);
                                 if(mode==ehospitals || hosp->variant == ppp.variant)
                                 {
                                     hospstr = "1";
                                     switch(hosp->oxygen)
                                     {
                                     case hosprecord::enan:
                                         oxygenstr = "";
                                         break;
                                     case hosprecord::eyes:
                                         oxygenstr = "1";
                                         oevent = true;
                                     break;
                                     case hosprecord::eno:
                                         oxygenstr = "0";
                                     break;
                                     }

                                     switch(hosp->icu)
                                     {
                                     case hosprecord::enan:
                                         icustr = "";
                                         break;
                                     case hosprecord::eyes:
                                         icustr = "1";
                                         uevent = true;
                                     break;
                                     case hosprecord::eno:
                                         icustr = "0";
                                     break;
                                     }
                                     event = true;
                                 }
                             }
                         }

                         if(mode == ehospitals)
                             os << hospstr << "," << oxygenstr << "," << icustr << ",";
                         else
                             os << ",,,";
                         string deathstr;
                         string variantdeathstr = "";
                         if((ppp.infdateasdeathdate == false
                                  && t2==truedeathbycovdate)
                             || (ppp.infdateasdeathdate == true
                                  && deadlyinfection && t2==deadlyinfection->t))
                         {
                             deathstr = "1";
                             if(mode == edeaths)
                                 event = true;
                             if(mode==evariantdeath && deadlyinfection)
                             {
                                if(deadlyinfection->variant == ppp.variant)
                                {
                                    variantdeathstr = "1";
                                    event = true;
                                }
                                else
                                    variantdeathstr = "0";
                             }
                         }
                         else
                         {
                             deathstr = "0";
                             if(mode==evariantdeath)
                                variantdeathstr = "0";
                         }
                        os << deathstr << ","
                           << (t2==deathbyotherdate ? "1" : "0" ) << ","
                           << variantinf << ",";

                        if(mode == evarianthosp)
                            os << hospstr << "," << oxygenstr << "," << icustr << ",";
                        else
                            os << ",,,";
                        os  << variantdeathstr << ",";
                     }
                }

                string vaccstatusstr;
                if(dooutput)
                {
                    vaccstatusstr =
                          ppp.groupvaccs
                            ? groupedvcovtexts[currentvaccstatus]
                            : vcovtexts[currentvaccstatus];

                    os << infpriorstr << ","
                       << severitystr << ","
                       << vaccstatusstr+boosteradd  << ","
                       << immunity << "," << age << ","
                       << agelabel << "," << gstr;

                    if(ppp.numericprevevents)
                    {
                        os << ",";
                        if(lastinfection)
                            os << lastinfection->t;
                        else
                            os << "_none";
                        os << ",";
                        if(lastvaccdate == maxint)
                            os << "_none";
                        else
                            os << lastvaccdate;
                    }
                    //erratum
                                     bool lastminuteexclude = false;
                                     for(unsigned k=0; k<ppp.postexcludevaccovs.size(); k++)
                                     {
                                        if(ppp.postexcludevaccovs[k]==immunity)
                                        {
                                            lastminuteexclude = true;
                                            break;
                                        }
                                        if(ppp.postexcludevaccovs[k]==agelabel)
                                        {
                                            lastminuteexclude = true;
                                            break;
                                        }
                                        if(ppp.postexcludevaccovs[k]==vaccstatusstr)
                                        {
                                            lastminuteexclude = true;
                                            break;
                                        }

                                     }

                    //erratum end


                    if(!lastminuteexclude)
                        o << os.str() << endl;
                    if(t1nonneg==0)
                    {
                        addto(lbls,startcnts,immunity);
//tables
                        addto(inflbls,infstartcnts,infpriorstr);
                        addto(vacclbls,vaccstartcnts,vaccstatusstr);
//tables-
                    }
                }

         bool recordevent = false;
         if(ppp.eventiso)
            recordevent = oevent;
         else if(ppp.eventisu)
            recordevent = uevent;
         else
            recordevent = event;

                if(recordevent && dooutput)
                {
                    oe << os.str();

                    for(unsigned j=0; j<enumlabels; j++)
                        oe <<  "," << data(i,j);
                    oe << endl;
                    addto(lbls,eventcnts,immunity);
//tables
                    addto(inflbls,infeventcnts,infpriorstr);
                    addto(vacclbls,vacceventcnts,vaccstatusstr);
//tables-

                }

                daysincovs[currentvaccstatus]+=t2-t1nonneg;


            }

            if(t2 >= enddate)
            {

                 processed++;

                 if(event)
                 {
                    if(t2<=0)
                        numeventsbeforestudy++;
                    else
                        numeventsbeinestudy++;
                 }
                 else
                 {
                     if(t2==T)
                        numsurvivedstudy++;
                     else if(t2<=0)
                        numcensoredbeforestudy++;
                     else
                        numcensoredinstudy++;
                 }


                 break;
            }
            if(t1 >= t2)
            {
                cout << "t1 >= t2 " << i << endl;
                throw;
            }

            currentinfstatus = newinfstatus;
            lastinfection = currentinfection;
            lastvaccdate = currentvaccdate;
            currentvaccstatus = newvaccstatus;
            t1 = t2;
         }
    }

    unsigned added = 0;
    if(!testrun && !(mode == ecomparison || mode == ehcomparison))
        for(unsigned m=0; m<=1; m++)
        {
            vector<unsigned>& vs = m ? men : women;
            for(unsigned a=0; a<=lastage; a++)
            {
                if(a >= minage && a <= maxage)
                {
                    int n = ofage(a,m) / static_cast<double>(everyn)-vs[a];
                    if(n < 0)
                    {
                        cout << "More of gender " << m << " ( " << vs[a]
                                << ") treated then exist of age " << a << " (" << ofage(a,m) / static_cast<double>(everyn) << endl;
    //                    cout << "age,men,woman" << endl;
    //                    for(unsigned i=0; i<=lastage; i++)
    //                        cerr << i << "," << men[i] << "," << women[i] << endl;

                    }
                    cout << "Generating " << n << " " << (m ? "men" : "women") << " of age " << a << endl;
                    arecs[age2groupnum(a)].added += n;

                    string agelabel;
                    if(ppp.fourages)
                        agelabel = fourage2group(a);
                    else
                         agelabel = age2group(a);
                    //erratum
                    bool lastminuteexclude = false;
                    for(unsigned k=0; k<ppp.postexcludevaccovs.size(); k++)
                    {
                       if(ppp.postexcludevaccovs[k]==agelabel)
                       {
                           lastminuteexclude = true;
                           break;
                       }
                    }
                    if(!lastminuteexclude) //erratum end
                        for(int j=0; j<n; j++,i++)
                        {


                            o << i << "," << 0 << "," << T << ","
                                           << "0,"
                                           << ((mode == ehospitals || mode == ehospitalsreinf) ? "0,0,0," : ",,,")
                                           << "0,"
                                           << "0,"
                                           << "0,"
                                           << (mode == evarianthosp ? "0,0,0," : ",,,")
                                           << (mode == evariantdeath ? "0," : ",")
                                           << "_noinf," << severitylabel(enotsevereorunknown) << ","
                                           << vcovtexts[eunvacc] << ","
                                           << "_noimmunity,"
                                           << a << "," ;


                            o << agelabel << ","
                                           << (m ? malestr : femalestr);
                            if(ppp.numericprevevents)
                               o << ",_none,_none";
                            o << endl;
                            added++;

                            numsincovs[eunvacc]++;
                            numsurvivedstudy++;
                        }
                }
            }
        }

    cout << "Summary:" << endl;
    cout << data.r()-1 << " records in " << input << endl;
    cout << "out of which:" << endl;
    cout << processed << " records were used for the analysis" << endl;
    cout << inconsistento << " records is inconsistent"  << endl;
    cout << baddaterecors << " records is with bad or out of range dates" << endl;
    cout << noagerecords << " lacks valid age information " << endl;
    cout << nogenderrecords << " lacks valid genderinformation " << endl;
    cout << deadcovbeforestart << " died of covid before time zero " << endl;
    cout << deadotherbeforestart << " died of other reasons before time zero " << endl;
    cout << endl;

    cout << hospitalunassigned << " records cannot assign infection to hospitalization, but left in study (hospitalization does not count if linked to infection)"  << endl;


    cout << "For the analysis:" << endl;
    cout << processed << " taken from NZIS database" << endl;
    cout << added << " persons added based on demographic structure" << endl;
    cout << added+processed << " total sample size" << endl;

    cout << "out of which..." << endl;

    cout << "num censored before study=" << numcensoredbeforestudy << endl;
    cout << "num events before study=" << numeventsbeforestudy << endl;
    cout << "num censored in study=" <<  numcensoredinstudy << endl;
    cout << "num events in estudy=" << numeventsbeinestudy << endl;
    cout << "num survived study=" << numsurvivedstudy << endl;
    cout << endl;

    cout << "Infections: " << numinfections << " reinfections: " << numreinfections << "( raw = " << numreinfectionsraw << ")" << endl;
    cout << "Horizon " << T << endl;

    cout << "Covariate stats" << endl;
    cout << "cov,num,average" << endl;
    for(unsigned i=0; i<enumvacccovs; i++)
        cout << vcovtexts[i] << "," << numsincovs[i] << ","
             << static_cast<double>(daysincovs[i])/numsincovs[i]  << endl;


    cout << endl;

      cout << "t,u,d,o" << endl;
      for(unsigned i=0; i<variants.size(); i++)
      {
          cout << i;
          for(unsigned j=0; j<enumvariants; j++)
              cout << "," << variants[i][j];
          cout << endl;
      }
      cout << endl;

/*    cout << "In addition, some records were dropped due to date conversion errors:" << endl
         << "Vaccination dates first: " << endl
         << v1datecounter.wrong << " wrong dates,"
         << v1datecounter.over << " dates over,"
         << v1datecounter.under << " dates under" << endl
         << "Vaccination dates second: " << endl
         << v2datecounter.wrong << " wrong dates,"
         << v2datecounter.over << " dates over,"
         << v2datecounter.under << " dates under" << endl
         << "Vaccination dates third: " << endl
         << v3datecounter.wrong << " wrong dates,"
         << v3datecounter.over << " dates over,"
         << v3datecounter.under << " dates under" << endl
         << "Infection dates : " << endl
         << do1counter.wrong << " wrong dates,"
         << do1counter.over << " dates over,"
         << do1counter.under << " dates under" << endl
         << "Infection2 dates : " << endl
         << do2counter.wrong << " wrong dates,"
         << do2counter.over << " dates over,"
         << do2counter.under << " dates under" << endl
         << "Death dates : " << endl
         << ucounter.wrong << " wrong  dates,"
         << ucounter.over << " dates over,"
         << ucounter.under << " dates under"
         << "Hosp dates : " << endl
         << hcounter.wrong << " wrong  dates,"
         << hcounter.over << " dates over,"
         << hcounter.under << " dates under" << endl; */

    cout << endl;

    acrecord sumr;
    for(unsigned i=0; i<enumagegroups; i++)
    {
        auto& r = arecs[i];
        sumr.num += r.num;
        sumr.added += r.added;
        sumr.included += r.included;
        sumr.deadbeforecov += r.deadbeforecov;
        sumr.deadbeforeother += r.deadbeforeother;
        sumr.deadaftercov += r.deadaftercov;
        sumr.deadafterother += r.deadafterother;
        sumr.infectedbefore += r.infectedbefore;
        sumr.hospbefore += r.hospbefore;
        sumr.hospafter += r.hospafter;
        sumr.infectedafter += r.infectedafter;
        for(unsigned v=0; v<enumvaccines; v++)
            sumr.firstdoseoftwoshot[v] += r.firstdoseoftwoshot[v];
        for(unsigned v=0; v<enumvaccines; v++)
            sumr.finished[v] += r.finished[v];
        for(unsigned v=0; v<enumvaccines; v++)
            sumr.booster[v] += r.booster[v];
    }
    arecs.push_back(sumr);

    for(unsigned i=0; i<=enumagegroups; i++)
    {
        const acrecord& r = arecs[i];
        tex << (i==enumagegroups ? "Total" : grouplabel(i)) << "&"
            << r.num << "&"
            << r.num-r.included-r.deadbeforecov-r.deadbeforeother << "&"
            << r.deadbeforecov << "&"
            << r.deadbeforeother << "&"
            << r.included << "&"
            << r.added << "&"
            << r.included + r.added << "&"
            << r.infectedafter << "&"
            << r.hospafter << "&"
            << r.deadaftercov << "&"
            << r.deadafterother << "\\\\"
            << endl;
    }

    tex << endl;
    tex << nogenderrecords << " records withou gender" << endl;
    tex << noagerecords << " records withou age" << endl;

    for(unsigned i=0; i<=enumagegroups; i++)
    {
        tex << (i==enumagegroups ? "Total" : grouplabel(i)) ;
        unsigned sf = 0;
        for(unsigned v=0; v<enumvaccines; v++)
        {
            const acrecord& r = arecs[i];
            tex << "&" << r.finished[v];
            sf += r.finished[v];
        }
        tex << "&" << sf;
        unsigned sb = 0;
        for(unsigned v=0; v<enumvaccines; v++)
        {
            const acrecord& r = arecs[i];
            tex << "&" << r.booster[v];
            sb += r.booster[v];
        }
        tex << "&" << sb << "\\\\" << endl;
    }

    ofstream on(output + ".ns.tex");
    if(!on)
    {
        cerr << "Cannot open " << output << ".ns.tex"<< endl;
        throw;
    }
    on << "Immunity & entered & events \\\\" << endl;
    for(unsigned i=0; i<lbls.size(); i++)
    {
        for(unsigned j=0; j<lbls[i].size(); j++)
        {
            auto c = lbls[i][j];
            on << (c == '_' ? "\\" : "") << c;
        }
        on << "&" << startcnts[i] << "&" << eventcnts[i] << "\\\\" << endl;
    }
//tables
    {
        ofstream on(output + ".is.tex");
        if(!on)
        {
            cerr << "Cannot open " << output << ".is.tex"<< endl;
            throw;
        }
        on << "InfPrior & entered & events \\\\" << endl;
        for(unsigned i=0; i<inflbls.size(); i++)
        {
            for(unsigned j=0; j<inflbls[i].size(); j++)
            {
                auto c = inflbls[i][j];
                on << (c == '_' ? "\\" : "") << c;
            }
            on << "&" << infstartcnts[i] << "&" << infeventcnts[i] << "\\\\" << endl;
        }
    }
    {
        ofstream on(output + ".vs.tex");
        if(!on)
        {
            cerr << "Cannot open " << output << ".vs.tex"<< endl;
            throw;
        }
        on << "VaccStatus & entered & events \\\\" << endl;
        for(unsigned i=0; i<vacclbls.size(); i++)
        {
            for(unsigned j=0; j<vacclbls[i].size(); j++)
            {
                auto c = vacclbls[i][j];
                on << (c == '_' ? "\\" : "") << c;
            }
            on << "&" << vaccstartcnts[i] << "&" << vacceventcnts[i] << "\\\\" << endl;
        }
    }
//tables-
}



int _main(int argc, char *argv[], bool compare = false)
{
    cout << "version 27 + lastminuteexclude + tables" << endl;
    cout << "Usage convertool input output lastdate(rrrr-mm-dd) whattodo(IPR) minage maxage count_every" << endl;
    if(!testrun  && argc < 5)
        throw "at least three arguments must be given";

    bool old = argv[4][0] < 'a';
    if(old)
    {
        o2rmodes mode;
        preprocessparams ppp;
        ppp.firstdatestr = "2020-12-26";
        switch(argv[4][0])
        {
            case 'O':
                mode = evariantinf;
                ppp.firstdatestr = ppp.discriminationtdatestr;
                cout << "omicron" << endl;
            break;

            case 'P':
                mode = evarianthosp;
                ppp.firstdatestr = ppp.discriminationtdatestr;
                cout << "omicron hospitalization" << endl;
            break;

            case 'I':
                mode = einfections;
                cout << "infections" << endl;
            break;
            case 'R':
                mode = ereinfections;
                ppp.firstdatestr = "2020-05-01";
                cout << "reinfections" << endl;
                break;
            case 'S':
            {
                ppp.maxinfstatus = 10;
                ppp.firstdatestr = "2020-05-01";
                ppp.covreinfduration = ppp.firstcovreinfduration = 8 * 7;
                mode = ereinfections;
                cout << "reinfections with 8w change" << endl;
            }

            case 'H':
                mode = ehospitals;
                cout << "Hospitals" << endl;
            break;
            case 'J':
                mode = ehospitalsreinf;
                cout << "Hospitals on reinfections TBD ASSURE REINFECTION" << endl;
            break;
            case 'D':
                mode = edeaths;
                cout << "Deaths" << endl;
            break;
            default:
               cerr << "Unknonn option " << argv[4][0] << endl;
               throw;
        }


        ppp.lastdatestr = argv[3];
        ockodata2R(argv[1], argv[2],
                   mode,
                   argc > 5 ? atoi(argv[5]) : 0,
                   argc > 6 ? atoi(argv[6]) : 333,
                   argc > 7 ? atoi(argv[7]) : 1,

                   ppp);
    }
    else // old
    {
        o2rmodes mode;
        preprocessparams ppp;
        if(argv[4][0] == 'g')
        {
            switch(argv[4][1])
            {
            case 'h':
               mode = ehospitals;
               ppp.infdateashospdate = true;
            break;
            case 'd':
                ppp.infdateasdeathdate = true;
                mode = edeaths;
             break;
            case 'i':
            case 0:
                mode = einfections;
                break;
            default:
                throw "unknown option following g";
            }

            ppp.fourages = false;
            ppp.firstcovreinfduration = 60;
            ppp.covreinfduration = 3*365; // no impact
            ppp.maxinfstatus = 2;
            ppp.regularcovvaccduration = 3*365;
            ppp.lastfullcovvaccduration = 3*365;
            ppp.lastboostercovvaccduration = 3*365;
            ppp.lastpartialcovvaccduration = 3*365;
            ppp.excludefirstcovreinfduration = true;
            ppp.numfinalcovs = 1;
            ppp.firstdatestr = "2020-12-26";

            ppp.numericprevevents = true;
        }
        else
        {
            ppp.firstcovreinfduration = 60;
            ppp.covreinfduration = 121;
            ppp.regularcovvaccduration = 61;
            ppp.lastpartialcovvaccduration = 121;
            ppp.lastfullcovvaccduration = 2*365;
            ppp.lastboostercovvaccduration = 2*365;
            ppp.firstdatestr = ppp.discriminationtdatestr;
            ppp.excludefirstcovreinfduration = true;
            ppp.excludeotherimmunity = true;
            ppp.excludevaccovs = {eAfirst1, eAfirst2plus, eA1};
            ppp.singlepartcov = true;
            ppp.groupvaccs = true;
            ppp.numericprevevents = true;

            if(argv[4][0] == 'c')
            {
                ppp.numfinalcovs = 2;
                ppp.maxinfstatus = 3;
                ppp.fourages = true;
                ppp.singlepartcov = true;
                ppp.Inf1_Xtoothers  = true;
                if(argv[4][1] == 'h')
                    mode = ehcomparison;
                else
                    mode = ecomparison;
            }
            else
            {
//                    ppp.fourages = true;
//                    ppp.groupvaccs = true;

                ppp.numfinalcovs = 3;
                ppp.maxinfstatus = 5;
                bool novariant = true;
                switch(argv[4][1])
                {
                case 'o':
                    ppp.variant = eomicron;
                    novariant = false;
                    break;
                case 'd':
                    ppp.variant = edelta;
                    novariant = false;
                    break;
                case '\0':
                    break;
                default:
                    throw "unknown variant";
                }
                if(strlen(argv[4]) > 2)
                {
                    if(argv[4][2] == '+')
                    {
                        ppp.groupvaccs = false;
                        ppp.singlepartcov = false;
                    }
                }


                switch(argv[4][0])
                {
                case 'r':
                    if(novariant)
                    {
                        mode = ereinfections;
                        cout << "reinfections" << endl;
                    }
                    else
                    {
                        mode = evariantinf;
                        cout << variantlabels[ppp.variant] << " reinfections" << endl;
                    }
                    break;
                case 'v':
                    if(novariant)
                        throw "missing variant";
                    else
                    {
                        mode = evariantinf;
                        cout << variantlabels[ppp.variant] << " infections" << endl;
                    }
                    break;
                case 'i':
                    mode = einfections;
                    cout << "infections" << endl;
                    break;
                case 'o':
                case 'u':
//                    ppp.Inf1_Xtoothers = true;
                    ppp.groupinteraccions = true;
                    ppp.eventiso = argv[4][0]=='o';
                    ppp.eventisu = argv[4][0]=='u';
//                    ppp.fourages = true;
                 // break missing intentinally
                case 'h':
                    ppp.infdateashospdate = true;
                    if(novariant)
                    {
                        mode = ehospitals;
                        cout << "hospitals" << endl;
                    }
                    else
                    {
                        mode = evarianthosp;
                        cout << variantlabels[ppp.variant] << " hospitalizations" << endl;
                    }
                    break;
                case 'd':
//                    ppp.Inf1_Xtoothers = true;
                    ppp.infdateasdeathdate = true;
                    if(novariant)
                    {
                        mode = edeaths;
                        cout << "deaths" << endl;
                    }
                    else
                    {
                        mode = evariantdeath;
                        cout << variantlabels[ppp.variant] << " deaths" << endl;
                    }
                    break;
                case 'e':
//                    ppp.Inf1_Xtoothers = true;
                    ppp.infdateasdeathdate = false;
                    ppp.excludefirstcovreinfduration = false;
                    ppp.excludeotherimmunity = false;
                    if(novariant)
                    {
                        mode = edeaths;
                        cout << "deaths" << endl;
                    }
                    else
                    {
                        mode = evariantdeath;
                        cout << variantlabels[ppp.variant] << " deaths" << endl;
                    }
                    break;

                default:
                   cerr << "Unknonn option " << argv[4][0] << endl;
                   throw;
                }
            }
        }

        //erratum begin
        for(unsigned i=0; argv[4][i]; i++)
        {
            if(argv[4][i]==':')
            {
                string c;
                bool end=false;
                for(unsigned j=i+1;;j++)
                {
                    char l = argv[4][j];
                    end = l==0;
                    bool next = l==',';
                    if(end || next)
                    {
                        if(c.size() > 0)
                        {
                            ppp.postexcludevaccovs.push_back(c);
                            cout << "Last minute excluding: " << c << endl;
                            c="";
                        }
                        if(end)
                            break;
                    }
                    else
                        c += l;
                }
            }
        }
        //erratum end

        ppp.lastdatestr = argv[3];
        ockodata2R(argv[1], argv[2],
                   mode,
                   argc > 5 ? atoi(argv[5]) : 0,
                   argc > 6 ? atoi(argv[6]) : 333,
                   argc > 7 ? atoi(argv[7]) : 1,
                   ppp);
/*        if(compare)
        {
            string cfn = argv[2];
            cfn += ".cmp.csv";
            oldockodata2R(argv[1], cfn.c_str(),
                       mode,
                       argc > 5 ? atoi(argv[5]) : 0,
                       argc > 6 ? atoi(argv[6]) : 333,
                       argc > 7 ? atoi(argv[7]) : 1,
                       ppp);
            string cmd = "cmp ";
            cmd += argv[2];
            cmd += " ";
            cmd += cfn;
            if(system(cmd.c_str()))
            {
                cerr << "option " << argv[4] << endl;
                throw "old != new";
            }
        }*/
     }
    return 0;

}


int main(int argc, char *argv[])
{
    double startt = time(0);

    try
    {
        if(!testrun)
            return _main(argc,argv);
        else
        {
//            throw "test mode disabled";
//            char *as[5] ={"foo",testfilename,"torinternal.csv",
//                          "2022-02-13","oo:12-15"};
//        return _main(5,as,false);

    //        _main(5,as, true);

//            as[4] = "ho+";
//            _main(5,as, true);

/*

            as[4] = "vo";
            _main(5,as, true);
            as[4] = "d";
            _main(5,as, true);
            as[4] = "e";
            _main(5,as, true);
            as[4] = "g";
            _main(5,as, true);
            as[4] = "gh";
            _main(5,as, true);

            as[4] = "c";
            _main(5,as, true); */
            return 0;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << endl;
        return 1;
    }
    catch (const char* m)
    {
           cerr << m << endl;
           return 1;
    }
    catch (const string& m)
    {
           cerr << m << endl;
           return 1;
    }
    catch(...)
    {
        cerr << "unknown exception" << endl;
        return 1;
    }


    cout << "time: " << time(0)-startt << " seconds." << endl;

    return 0;

}



