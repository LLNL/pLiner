#ifndef _FP_DEBUGGER_HEADER
#define _FP_DEBUGGER_HEADER

extern std::string infofname;

// profiling file
extern std::string prof_prefix;

// functions that appear on the file
extern std::vector<std::string> funclist;

// function name, start/end line number
extern std::set<std::string> pfuncs;
extern std::map<std::string, std::vector<std::pair<unsigned, unsigned>>> pfregions; 
extern bool transWholeFunc; 

// high precision
extern std::string myreal;

// output file
extern std::string outfilename;
#endif
