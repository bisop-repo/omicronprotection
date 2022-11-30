#include "tooltools.hpp"
#include <fstream>

char testfilename[] = "/home/martin/tmp/v3/part/xaa.csv";

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
string femalestr = "F";
string czfemalestr = "Z";

string unvacclabel = "_unvaccinated";
string uninflabel = "_uninfected";

string gender2str(bool male)
{
    return male ? "M" : "F";
}

enum eagegroups { v0011, v1215, v1617, v1824, v2529, v3034, v3539, v4044,v4549, v5055,v5559, v6054,v6559, v7074,v7579, v80plus, enumagegroups };




constexpr unsigned lastage = 100;

reldate dateoffirstczsohalfyear = date2int("2020-01-01");

unsigned numpeopleofage(unsigned age, bool male, unsigned halfyear)
{
#include "ages.inc"

    assert(age <= lastage);
    assert(men.size()==lastage+1);
    assert(women.size()==lastage+1);
    return male ? men[age][min(halfyear,static_cast<unsigned>(men[age].size()-1))]
            : women[age][min(halfyear,static_cast<unsigned>(women[age].size()-1))];
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

/*
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
*/


// pasted from vakciny_ciselnik
struct vaccinerecord
{	string code;
    string description;
    int numshots;
    bool consorfull;
    bool consorboost;
    string abbrev;
};

vector<vaccinerecord> vaccines={
    {"CO01","Comirnaty",2,false,false,"P"},
    {"CO02","SPIKEVAX",2,false,false,"M"},
    {"CO03","VAXZEVRIA",2,false,false,"A"},
    {"CO04","COVID-19 Vaccine Janssen",1,false,false,"J"},
    {"CO06","Comirnaty 5-11",2,false,false,"P511"},
    {"CO07","Nuvaxovid",2,false,false,"N"},
    {"CO10","Covovax",2,false,false,"C"},
    {"CO11","Sinopharm",2,false,false,"string abbrev"},
    {"CO12","Sinovac",2,false,false,"V"},
    {"CO13","COVAXIN",2,false,false,"X"},
    {"CO14","Covishield",2,false,false,"S"},
    {"CO08","Comirnaty Original/Omicron BA.1",2,false,false,"PO1"},
    {"CO09","Comirnaty Original/Omicron BA.4/BA.5",2,false,false,"PO4"},
    {"CO15","Spikevax bivalent Original/Omicron BA.1",2,false,false,"MB"},
    {"CO05","Sputnik V",2,false,false,"U"},
    {"CO16","Comirnaty 6m-4",2,false,false,"P6"},
    {"CO17","Valneva",2,false,false,"N"}
};

unsigned eunknownvaccine = vaccines.size();
unsigned numvaccines = vaccines.size();

unsigned vacc2vacc(string code)
{
    for(unsigned i=0; i<numvaccines; i++)
        if(code==vaccines[i].code)
            return i;
    return eunknownvaccine;
}

struct variantrecord
{
  string codeindata;
  string codeinoutput;
  string codeincovariate;
  string commandlineid;
};

vector<variantrecord> variants
{
    { "", "NA_Other","NA","n"},
    { "Delta", "Delta","Delta", "d"},
    { "Omikron", "Omicron", "Omicron", "o"},
};

auto navariant = 0;
auto allvariants = variants.size();

struct preprocessparams
{
    /// least date possible (others reported as errors
    int zerodate = date2int("2020-01-01");

    /// delay after the first, second, third and fourth shot takes effect
    int regulardelay = 14;
    int boostdelay = 7;

    /// lenght of the window after infection within which hospitalization is examined
    /// (after this limit, the subject is censored in h analysis TBD CHECK THIS!!)
    int outcomelimit = 15;

    reldate safetydate = date2int("2022-12-01");

    /// time delay during which new positive tests are not regarded as reinfections
    int infectionsgap = 60;

    /// number of the last postinf covariate (0 = not infected, 1 - first ...)
    int numinfcovariates = 6;

    /// duration of 1st  postinf covariate
    int firstcovreinfduration = 60;

    /// duration of 2nd ... \p (naxinfstatus-1)-th - postinf covariate (the last one lasts till infty)
    int covreinfduration = 61;

    /// durations of the other than the last postvacc covariates
    int regularcovvaccduration = 61;


    /// number of covariates following partial (including the last one)
    int numpartialcovs = 2;

    /// number of covariates following full vacc (including the last one)
    int numfinalcovs = 4;

    int numboostercovs = 3;

    int numsecboostercovs = 2;


    /// time after the test for the treatment to be assigned to the test
    ///
    int hosplimit = 30;


    /// if true, then only four age categories are used instead of the finer division
    bool fourages = false;

    /// if true then vaccines are grouped in the VaccStatus field
    bool groupvaccs = false;

    bool groupvariants = false;


    /// Inputs that should be provided

    /// start of the sutedy (time 0)
    string firstdatestr;

    /// horzion of the study (time T - once hosps are determined by corresponding
    /// infections, only events (infections) hosplimit is taken from T to get new
    /// horizon (so that the fact of hosp could be decided, similarly deaths and deathlimit)
    string lastdatestr;

    /// variant (if examined)
    unsigned variant = allvariants;
};

/*

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
}*/


enum o2rmodes { einfections, ecovidproxy };



vector<string> mdelabels = { "infections", "covidproxy" };

void ockodata2R(string input, string output,
                o2rmodes mode,
                unsigned minage, unsigned maxage, 
                preprocessparams ppp = preprocessparams() ) // rozdelane
{
    reldate firstdate;
    try
    {
        firstdate = date2int(ppp.firstdatestr);
    }
    catch(...)
    {
        cerr << "Error converting first date string " + ppp.firstdatestr;
        throw;
    }

    reldate lastdate;
    try
    {
        lastdate = date2int(ppp.lastdatestr);
    }
    catch(...)
    {
        cerr << "Error converting last date string " + ppp.lastdatestr;
        throw;
    }


    cout << "Mode " << mdelabels[mode] << endl;

    cout << "Study period: " << ppp.firstdatestr << " to " << ppp.lastdatestr << endl;

    cout << "Age filter: " << minage << "-" << maxage << endl;

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

    ofstream ou(output + ".unprocessed.csv");
    if(!ou)
    {
        cerr << "Cannot open " + output + ".unprocessed.csv" << endl;
        throw;
    }

    ou << "error";
    
    
/*    ofstream tex(output + ".tex");
    if(!tex)
    {
       cerr << "Cannot open " + output + ".tex" << endl;
       throw;
    }*/

    ostringstream header;

    header << "ID,T1,T2,Infected,Covidproxy,DeadByCovid, DeadByOther,";
//    for(unsigned i=0; i<variants.size(); i++)
//        header << variants[i].codeincovariate << "Inf,";
    header << "InfPrior,VaccStatus,Age,AgeGr,Sex";
//    header << ",InfPriorTime,LastVaccTime";

    o << header.str() << endl;
    oe << header.str();


    enum egender { emale, efemale, enumgenders };

    enum evaccorder { novacc, firstdose, finaldose, firstbooster, secbooster, enumvaccorders, eunknownvaccorder = enumvaccorders };



    cout << "Input " << input << endl;
    csv<';'> data(input);

    cout << "Importing from input, total" << data.r()-1 <<
         " records." << endl;

    static vector<string> labels = {
        "ID",	"infekce",	"pohlavi",	"vek",	"Kraj_bydliste",	"ORP_Bydliste",	"Datum_pozitivity",	"DatumVysledku",	"Vylecen",	"Umrti",	"symptom",	"typ_testu",	"PrvniDavka",	"DruhaDavka",	"Ukoncene_ockovani",	"Extra_davka",	"Druha_extra_davka",	"OckovaciLatkaKod1",	"OckovaciLatkaKod2",	"OckovaciLatkaKod3",	"OckovaciLatkaKod4",	"bin_Hospitalizace",	"min_Hospitalizace",	"dni_Hospitalizace",	"max_Hospitalizace",	"bin_JIP",	"min_JIP",	"dni_JIP",	"max_JIP",	"bin_STAN",	"min_STAN",	"dni_STAN",	"max_STAN",	"bin_Kyslik",	"min_Kyslik",	"dni_Kyslik",	"max_Kyslik",	"bin_HFNO",	"min_HFNO",	"dni_HFNO",	"max_HFNO",	"bin_UPV_ECMO",	"min_UPV_ECMO",	"dni_UPV_ECMO",	"max_UPV_ECMO",	"Mutace",	"DatumUmrtiLPZ"
    };
            
            
    enum elabels {ID,	infekce,	pohlavi,	vek,	Kraj_bydliste,	ORP_Bydliste,	Datum_pozitivity,	DatumVysledku,	Vylecen,	Umrti,	symptom,	typ_testu,	PrvniDavka,	DruhaDavka,	Ukoncene_ockovani,	Extra_davka,	Druha_extra_davka,	OckovaciLatkaKod1,	OckovaciLatkaKod2,	OckovaciLatkaKod3,	OckovaciLatkaKod4,	bin_Hospitalizace,	min_Hospitalizace,	dni_Hospitalizace,	max_Hospitalizace,	bin_JIP,	min_JIP,	dni_JIP,	max_JIP,	bin_STAN,	min_STAN,	dni_STAN,	max_STAN,	bin_Kyslik,	min_Kyslik,	dni_Kyslik,	max_Kyslik,	bin_HFNO,	min_HFNO,	dni_HFNO,	max_HFNO,	bin_UPV_ECMO,	min_UPV_ECMO,	dni_UPV_ECMO,	max_UPV_ECMO,	Mutace,	DatumUmrtiLPZ, enumlabels};

    for(unsigned i=0; i<enumlabels; i++)
    {
        oe << "," << labels[i];
        ou << "," << labels[i];
    }
    oe << endl;
    ou << endl;

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


    vector<unsigned> men(lastage+1,0);
    vector<unsigned> women(lastage+1,0);
    

    struct covstatrecord
    {
        string covlabel;
        int events = 0;
        int days = 0;
    };
    
    
    vector<covstatrecord> cpvstat;

    cout << "Processing records from input, excluding inconsistent records:" << endl;

//    vector<vector<unsigned>> variants(lastdate-ppp.zerodate+1,vector<unsigned>(enumvariants,0));

    struct vaccinationrecord {
                      reldate t = maxreldate;
                      evaccorder vaccorder = eunknownvaccorder;
                      unsigned vac = eunknownvaccine;
     };


    struct infectionrecord
    {
        int t;
        unsigned variant;
        bool covidproxy = false;
    };




    unsigned firstnext;
    unsigned maxid = 0;
    int T = lastdate - firstdate;
    for(unsigned i=1;
i <=1000 &&
        i<data.r(); i=firstnext )
    {
        reldate deathcoviddate = maxreldate;
        reldate deathotherdate = maxreldate;


        vector<infectionrecord> infections;

        vector<vaccinationrecord> vaccinations;

// when used, all these macros have to be enclused in braces

#define REPORT(X) for(unsigned j=0; j<is.size(); j++) \
        { \
            ou << "\"" << X << "\""; \
            for(unsigned k=0; k<enumlabels; k++) \
                ou << "," << data(is[j],k); \
            ou << endl; \
        }


        string idstr = data(i,ID);
        unsigned id;
        try
        {
            id = stoul(idstr);
            if(id > maxid)
                maxid = id;
        }
        catch (...)
        {
            cerr << "Cannot convert ID '" << idstr << "' to unsigned" << endl;
            throw;
        }
        
        constexpr int norecord = -1;
        vector<int> is;
        for(unsigned j=i; j<data.r(); j++)
        {
            string newidstr = data(j,ID);
            if(newidstr!=idstr)
                break;
            is.push_back(norecord);
        }
//        bool error = false;
        bool emptyfound = false;
        for(unsigned j=i; j<i+is.size(); j++)
        {
            if(data(j,infekce)=="")
            {
                if(emptyfound)
                {
                    cerr << "row " << j << " two empty lines" << endl;
                    throw;
                }
                if(j!=i)
                {
                    cerr << "row" << j << "empty line on non-first place" << endl;
                    throw;
                }
                emptyfound = true;
                is[j-i]=j;
            }
            else
            {
                int infindex = data(j,infekce)[0] - '1';
                if(infindex < 0 || infindex >= is.size())
                {
                    cerr << "field infekce = " << data(j,infekce) << endl;
                    throw;
                }
                is[infindex] = j;
            }
        }
        for(unsigned k=0; k<is.size(); k++)
            if(is[k] == norecord)
            {
                cerr << "invalid record group starting at " << i << endl;
                throw;
            }

        bool throwthisid = false;
        string errorstring = "";

    #define THROW(X,W) { throwthisid = true; REPORT(X) ; W;  }
    #define THROWS(X,W) { ostringstream o; o<< X; REPORT(o.str()); throwthisid = true; W; }
    #define GETDATE(Y,X,W) { bool error; Y=date2int(X,ppp.zerodate, ppp.safetydate, error, errorstring)-ppp.zerodate; if(error) { throwthisid = true; REPORT(errorstring)  W; }   }
    #define GETVACC(V,S,L,W) { V = vacc2vacc(data(j,L)); S = vaccines[V].numshots == 1; if(V==eunknownvaccine) { throwthisid = true; errorstring = data(j,L) + " is an unknonw vaccine code."; REPORT(errorstring); W; } }


        firstnext = i + is.size();
        bool firstrecord = true;
        bool isdead = false;
        reldate disttofirst = maxreldate;
        unsigned relevantrecord;

        unsigned oldi=i;

        for(unsigned k=0; k<is.size(); k++)
        {
            if(isdead)
            {
                THROW("Extra line after a death record",break);
            }
            unsigned j = is[k];

            reldate infdate;
            string infdatestr = data(j,Datum_pozitivity);
            if(infdatestr == "")
                infdate = maxreldate;
            else
            {
                GETDATE(infdate,infdatestr,break);
                if(emptyfound)
                {
                    THROW("Empty infection order but non-empty date", break)
                }
            }


            reldate relevantvaccdate = maxreldate;
            if(firstrecord)
            {
                reldate firstvaccdate;
                string firstvaccdatestr = data(j,PrvniDavka);
                if(firstvaccdatestr == "")
                    firstvaccdate = maxreldate;
                else
                {
                    GETDATE(firstvaccdate,firstvaccdatestr, break);
                    bool s;
                    unsigned v;
                    GETVACC(v,s,OckovaciLatkaKod1,break);
                    assert(v<vaccines.size());
                    vaccinations.push_back(
                                 { /* t */ firstvaccdate  + ppp.regulardelay ,
                                   /* vaccorder */s ? finaldose : firstdose,
                                   /* vac */ v
                                  });
                    if(!s && data(j,DruhaDavka)=="")
                    {
                        THROW("Missing second shot!",break);
                    }
                }

                relevantvaccdate = firstvaccdate;

                reldate secvaccdate;
                string secvaccdatestr = data(j,DruhaDavka);
                if(secvaccdatestr == "")
                    secvaccdate = maxreldate;
                else
                {
                    if(firstvaccdate == maxreldate)
                    {
                        THROW("First shot missing", break);
                    }
                    GETDATE(secvaccdate,secvaccdatestr,break);
                    bool s;
                    unsigned v;
                    GETVACC(v,s,OckovaciLatkaKod2,break);
                    assert(v<vaccines.size());
                    if(s)
                    {
                        THROW("Second shot by single shot vaccine", break);
                    }
                    vaccinations.push_back(
                                 { /* t */ secvaccdate + ppp.regulardelay,
                                   /* vaccorder */ finaldose,
                                   /* vac */ v
                                  });
                }

                reldate firstextravaccdate;
                string firstextravaccdatestr = data(j,Extra_davka);
                if(firstextravaccdatestr == "")
                    firstextravaccdate = maxreldate;
                else
                {
                    if(firstvaccdate == maxreldate)
                    {
                        THROW("First shot missing", break);
                    }
                    GETDATE(firstextravaccdate,firstextravaccdatestr, break);
                    bool s;
                    unsigned v;
                    GETVACC(v,s,OckovaciLatkaKod3, break);
                    assert(v<vaccines.size());
                    vaccinations.push_back(
                                 { /* t */ firstextravaccdate + ppp.boostdelay,
                                   /* vaccorder */ firstbooster,
                                   /* vac */ v
                                  });

                }
                reldate secextravaccdate;
                string secextravaccdatestr = data(j,Druha_extra_davka);
                if(secextravaccdatestr == "")
                    secextravaccdate = maxreldate;
                else
                {
                    if(firstextravaccdate == maxreldate)
                    {
                        THROW("First extra vacc missing", break);
                    }
                    GETDATE(secextravaccdate,secextravaccdatestr, break);
                    bool s;
                    unsigned v;
                    GETVACC(v,s,OckovaciLatkaKod4, break);
                    assert(v<vaccines.size());
                    vaccinations.push_back(
                                 { /* t */ secextravaccdate + ppp.boostdelay,
                                   /* vaccorder */ secbooster,
                                   /* vac */ v
                                  });
                }
                for(unsigned k=0; k+1<vaccinations.size(); k++)
                    if(vaccinations[k].t >= vaccinations[k+1].t)
                    {
                        THROW("Wrong odering of shot dates.", break);
                    }

            }

            if(infdate < maxreldate)
            {
                unsigned k = 0;
                for(; k<variants.size(); k++)
                    if(data(j,Mutace)==variants[k].codeindata)
                        break;
                if(k==variants.size())
                    k = navariant;
                reldate oxygendate;
                string oxygendatestr = data(j,min_Kyslik);
                if(oxygendatestr != "")
                {
                    GETDATE(oxygendate,oxygendatestr,break)
                }
                else
                    oxygendate = maxreldate;
                reldate upvecmodate;
                string upvecmodatestr = data(j,min_UPV_ECMO);
                if(upvecmodatestr != "")
                {
                    GETDATE(upvecmodate,upvecmodatestr, break );
                }
                else
                    upvecmodate = maxreldate;
                bool proxy =
                        (data(i,bin_Kyslik) == "1" && oxygendate - infdate <= ppp.hosplimit)
                                   || (data(j,bin_UPV_ECMO) == "1" && upvecmodate - infdate <= ppp.hosplimit) ;

                infections.push_back({ infdate, k, proxy });
            }

            string deathcoviddatestr = data(j,Umrti);
            if(deathcoviddatestr != "")
            {
                GETDATE(deathcoviddate,deathcoviddatestr,break);
            }

            string deathotherdatestr = data(j,DatumUmrtiLPZ);
            if(deathotherdatestr != "")
            {
                GETDATE(deathotherdate,deathotherdatestr,break);
            }

            reldate relevantdate = emptyfound ?
                relevantvaccdate : infdate;
            if(relevantdate > ppp.safetydate)
            {
                THROW("Relevant date beyond safety date", break)
            }
            if(abs(firstdate-relevantdate) < disttofirst)
            {
                disttofirst = abs(firstdate-relevantdate);
                relevantrecord = j;
            }

            firstrecord = false;
        }
        if(throwthisid)
            continue;

        string gstr = data(oldi,pohlavi);

        bool male;
        if(gstr != malestr && gstr != femalestr && gstr != czfemalestr)
        {
            THROWS("Unknown gender " << gstr,continue);
        }
        else
            male = gstr == malestr;


        string agestr = data(relevantrecord,vek);
        unsigned age;
        if(agestr=="")
        {
            THROW("Missing age.",continue);
        }
        else
        {
            try
            {
                age = stoul(agestr);
                if(age < minage || age > maxage)
                {
                    THROWS("Age "<< agestr << " out of range",continue);
                }
            }
            catch (...)
            {
                THROWS("Cannot convert age '" << agestr << "' to unsigned",continue);
            }
        }

        unsigned agegroup=age2groupnum(age);

        assert(agegroup < enumagegroups);

        struct vaccstatus
        {
            evaccorder order;
            unsigned vaccine;
            unsigned covno;
        };

        int lastinfdate = maxreldate;
//         eseverity lastinfseverity = enotsevereorunknown;

        vaccstatus currentvaccstatus= { novacc, eunknownvaccine, 0 };

        reldate t1 = ppp.zerodate - firstdate; // may be negative, I know, I count wizth it

        unsigned nextinfptr = 0;
        unsigned nextvaccptr = 0;

        reldate enddate = T;

        if(mode == ecovidproxy)
            enddate = min(enddate,T-ppp.hosplimit);

        enddate = min(min(deathcoviddate,deathotherdate),enddate);
        int currentinfstatus = 0;
//        infectionrecord* lastinfection = 0;
        infectionrecord* currentinfection = 0;

//        reldate lastvaccdate = maxreldate;
//        reldate currentvaccdate = maxreldate;
        reldate lastvaccstatusdate = maxreldate;

        throwthisid = false;

cout << "id " << id << " infs " << infections.size() << " vaccs " << vaccinations.size() << endl ;

         for(;;)
         {
             unsigned newinfstatus = currentinfstatus;
             reldate nextinfdate = maxreldate;

             for(;nextinfptr < infections.size(); nextinfptr++)
             {
                 nextinfdate = infections[nextinfptr].t;
                 break;
             }

             int nextvaccdate = maxreldate;
             if(nextvaccptr < vaccinations.size())
                 nextvaccdate = vaccinations[nextvaccptr].t;

             int nextinfstatusupdate;
             if(currentinfstatus == 0 || currentinfstatus == ppp.numinfcovariates)
                 nextinfstatusupdate = maxreldate;
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

             vaccstatus newvaccstatus = currentvaccstatus;
             reldate nextvaccstatusdate;
             vaccstatus candidatevaccstatus = currentvaccstatus;


             if(currentvaccstatus.order == novacc)
                 nextvaccstatusdate = maxreldate;
             else
             {
                 assert(lastvaccstatusdate < maxreldate);

                 bool last = false;

                 switch(currentvaccstatus.order)
                 {
                     case novacc:
                         assert(0);
                     break;
                     case firstdose:
                         assert(currentvaccstatus.covno <ppp.numpartialcovs);
                         last = currentvaccstatus.covno+1 == ppp.numpartialcovs;
                     break;
                     case finaldose:
                         assert(currentvaccstatus.covno <ppp.numfinalcovs);
                         last = currentvaccstatus.covno+1 == ppp.numfinalcovs;
                     break;
                     case firstbooster:
                         assert(currentvaccstatus.covno <ppp.numboostercovs);
                         last = currentvaccstatus.covno+1 == ppp.numboostercovs;
                     break;
                     case secbooster:
                         assert(currentvaccstatus.covno <ppp.numsecboostercovs);
                         last = currentvaccstatus.covno+1 == ppp.numsecboostercovs;
                     break;
                     case eunknownvaccorder:
                         assert(0);
                         break;
                     default:
                         assert(0);
                         break;
                 }
                 if(last)
                     nextvaccstatusdate = maxreldate;
                 else
                 {
                     candidatevaccstatus = currentvaccstatus;
                     candidatevaccstatus.covno++;
                     nextvaccstatusdate = lastvaccstatusdate + ppp.regularcovvaccduration;
                 }
             }

             int t2 = min(nextvaccdate,
                          min(nextinfdate,
                          min(nextvaccstatusdate,
                          min(nextinfstatusupdate,enddate))));
     if(id == 22)
                 id = 22;

             if(t2==nextvaccstatusdate)
             {
                 lastvaccstatusdate = t2;
                 newvaccstatus = candidatevaccstatus;
             }


             if(t2==nextinfstatusupdate)
                 newinfstatus++;

             if(t2==nextvaccdate)
             {
                 vaccinationrecord e = vaccinations[nextvaccptr++];
                 assert(e.vac < vaccines.size());
                 assert(e.vaccorder >= firstdose);
                 if(e.vaccorder == firstdose)
                 {
                     assert(currentvaccstatus.order == novacc);

                     newvaccstatus.covno = 0;
                     newvaccstatus.order = firstdose;
                     newvaccstatus.vaccine = e.vac;
                 }
                 else if(e.vaccorder == finaldose)
                 {
                     newvaccstatus.covno = 0;
                     newvaccstatus.order = finaldose;
                     newvaccstatus.vaccine = e.vac;
                 }
                 else if(e.vaccorder == firstbooster)
                 {
                     assert(currentvaccstatus.order == finaldose);

                     newvaccstatus.covno = 0;
                     newvaccstatus.order = firstbooster;
                     newvaccstatus.vaccine = e.vac;
                 }
                 else if(e.vaccorder == secbooster)
                 {
                     assert(currentvaccstatus.order == firstbooster);

                     newvaccstatus.covno = 0;
                     newvaccstatus.order = secbooster;
                     newvaccstatus.vaccine = e.vac;
                 }
                 else
                     assert(0);
                 lastvaccstatusdate = t2;

//                 lastvaccdate = t2;
//                 currentvaccdate = t2;
             }

             int infected;
             int covidproxy;
             bool isevent;
             if(t2 == nextinfdate)
             {
                 newinfstatus = 1;
                 lastinfdate = t2;

                 currentinfection = &(infections[nextinfptr]);

                 nextinfptr++;
                 infected  =
                      ppp.variant == allvariants ? 1 : (currentinfection->variant == ppp.variant);
                 covidproxy = infected * currentinfection->covidproxy;

                 if(mode == einfections)
                     isevent = infected;
                 else
                     isevent = covidproxy;
             }
             else
             {
                 infected = 0;
                 covidproxy = 0;
                 isevent = false;
             }
             int deadbycovid = t2==deathcoviddate;
             int deadbyother = t2==deathotherdate;

             if(t2>0)
             {
                 int t1nonneg = max(0,t1);

                 string infpriorstr;
                 if(currentinfstatus == 0)
                     infpriorstr = uninflabel;
                 else
                 {
                     ostringstream os;
                     assert(nextinfptr > 0);
                     os << "inf_";
                     if(!ppp.groupvariants)
                     {
                         os << variants[infections[nextinfptr-1].variant].codeincovariate << "_";
                     }
                     int from,to;
                     switch(currentinfstatus)
                     {
                         case 0:
                             assert(0);
                         break;
                         case 1:
                             from = 1;
                             to = ppp.firstcovreinfduration;
                         break;
                         default:
                             assert(currentinfstatus <= ppp.numinfcovariates);
                        {
                             from = ppp.firstcovreinfduration
                                   + ppp.covreinfduration * (currentinfstatus-2) + 1;
                             to = from + ppp.covreinfduration-1;
                        }
                     }
                     os << from;
                     if(currentinfstatus == ppp.numinfcovariates)
                         os << "+";
                     else
                         os << "-" << to;
                     infpriorstr = os.str();
                 }

                 string vaccstring;
                 if(currentvaccstatus.order == novacc)
                 {
                     vaccstring = unvacclabel;
                 }
                 else
                 {
                     ostringstream os;
                     unsigned nc;
                     switch(currentvaccstatus.order)
                     {
                     case firstdose:
                         os << "partial";
                         nc = ppp.numpartialcovs;
                         break;
                     case finaldose:
                         os << "full";
                         nc = ppp.numfinalcovs;
                         break;
                     case firstbooster:
                         os << "boost";
                         nc = ppp.numboostercovs;
                         break;
                     case secbooster:
                         os << "secboost";
                         nc = ppp.numsecboostercovs;
                         break;
                     default:
                         assert(0);
                     }
                     os << "_";
                     if(!ppp.groupvaccs)
                         os << vaccines[currentvaccstatus.vaccine].code << "_";

                     int from, to;
                     from = currentvaccstatus.covno * ppp.regularcovvaccduration + 1;
                     to = from + ppp.regularcovvaccduration - 1;
                     os << from;
                     if(currentvaccstatus.covno+1 < nc)
                         os << "-" << to;
                     else
                         os << "+";
                     vaccstring = os.str();
                 }


                 ostringstream os;
                 os << idstr << "," << t1nonneg << "," << t2 << ","
                    << infected << "," << covidproxy << ","
                    << deadbycovid  << "," << deadbyother << "," ;
//                 for(unsigned k=0; k<variants.size(); k++)
//                     os << (k==infvariant ? infected : 0) << ",";
                 os << infpriorstr << "," << vaccstring << ","
                    << age << "," << grouplabel(agegroup) << ","
                    << gender2str(male);

                 o << os.str() << endl;

                 if(isevent)
                 {
                     oe << os.str();

                     for(unsigned j=0; j<enumlabels; j++)
                         oe <<  "," << data(i,j);
                     oe << endl;
                 }

                 if(t2 >= enddate)
                     break;
                 if(t1 >= t2)
                 {
                     cout << "t1 >= t2 id =" << id << endl;
                     throw;
                 }

              }
              currentinfstatus = newinfstatus;
//              lastinfection = currentinfection;
//              lastvaccdate = currentvaccdate;
              currentvaccstatus = newvaccstatus;
              t1 = t2;
           }
         if(throwthisid)
         {
             for(unsigned j=0; j<is.size(); j++)
             {
                 oe << """" << errorstring << """";
                 for(unsigned k=0; k<enumlabels; k++)
                     oe << "," << data(is[j],k);
                 oe << endl;
             }
             continue;
         }

    }
    // add missing people

    assert(firstdate >= dateoffirstczsohalfyear);
    auto czsohalfyear = (firstdate - dateoffirstczsohalfyear) / 366;

    if(!testrun)
        for(unsigned m=0; m<=1; m++)
        {
            vector<unsigned>& vs = m ? men : women;
            for(unsigned a=0; a<=lastage; a++)
            {
                if(a >= minage && a <= maxage)
                {
                    int n = numpeopleofage(a,m,czsohalfyear)-vs[a];
                    if(n < 0)
                    {
                        cout << "More of gender " << m << " ( " << vs[a]
                                << ") treated then exist of age " << a << " (" << numpeopleofage(a,m,czsohalfyear)  << endl;
    //                    cout << "age,men,woman" << endl;
    //                    for(unsigned i=0; i<=lastage; i++)
    //                        cerr << i << "," << men[i] << "," << women[i] << endl;

                    }
                    cout << "Generating " << n << " " << (m ? "men" : "women") << " of age " << a << endl;

                    string agelabel;
                    if(ppp.fourages)
                        agelabel = fourage2group(a);
                    else
                         agelabel = age2group(a);
                    //of course we do note guarantee ids to follow the "true ones". (maybe we should check whether we do not duplicate ids)
                    unsigned i = maxid+1;
                    for(int j=0; j<n; j++,i++)
                    {


//                        "ID,T1,T2,Infected,Covidproxy,DeadByCovid, DeadByOther,";
                        o << i << "," << 0 << "," << T << ",";

//                             for(unsigned i=0; i<variants.size(); i++)
//                                 header << variants[i].codeinoutput << "Inf,";

//                        for(unsigned k=0; k<variants.size(); k++)
//                             o << "0,";

//                         header << "InfPrior,VaccStatus,Age,AgeGr,Sex";

                        o << uninflabel << "," << unvacclabel << "," <<  "0,0,0,0,"
                          << a << ","
                          << agelabel << "," << gender2str(n) << endl;
                     }
                 }
            }
        }


}



int _main(int argc, char *argv[], bool compare = false)
{
    cout << "version 2.0" << endl;
    cout << "Usage convertool input output firstdate(rrrr-mm-dd) lastdate whattodo(IPR) minage maxage count_every" << endl;
    if(!testrun  && argc < 6)
        throw "at least five arguments must be given";

    {
        o2rmodes mode;
        preprocessparams ppp;
        {
            ppp.groupvaccs = true;

                unsigned v=0;
                for(; v<variants.size(); v++)
                {
                    if(argv[5][1]==variants[v].commandlineid[0])
                        break;
                }

                ppp.variant = v;

                if(strlen(argv[5]) > 2)
                {
                    if(argv[5][2] == '+')
                        ppp.groupvaccs = false;
                }


                switch(argv[5][0])
                {
                case 'i':
                    mode = einfections;
                    cout << "infections" << endl;
                    break;
                case 'x':
                    mode = ecovidproxy;
                    cout << "covid proxy" << endl;
                    break;
                default:
                   cerr << "Unknonn option " << argv[4][0] << endl;
                   throw;
                }
        }


        ppp.firstdatestr = argv[3];
        ppp.lastdatestr = argv[4];
        ockodata2R(argv[1], argv[2],
                   mode,
                   argc > 6 ? atoi(argv[6]) : 0,
                   argc > 7 ? atoi(argv[7]) : 333,
                   ppp);
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
            char *as[6] ={"foo",testfilename,"torinternal.csv",
                          "2020-06-01","2022-06-30","io"};
            return _main(6,as,false);
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



