import os
import re
import ast

programs_match = []
programs_mismatch = []
pliner_isolation_failed_list = []
class ParsedLine:
    def __init__(self, block_type, function_dict, output, transformed_output):
        self.block_type = block_type
        self.function_dict = function_dict
        self.output = output
        self.transformed_output = transformed_output

def parse_line(line):
    block_type = line.split(":",1)[0]
    try:
        function_dict = ast.literal_eval(re.search('{(.+?)}', line).group(0))
    except Exception:
        function_dict = {}
    output = line.split(",")[-1].strip()
    transformed_output = line.split(",")[-2].strip()
    return ParsedLine(block_type, function_dict, output, transformed_output)

for value in range(1, 51):
    file_name = 'test_'+str(value)+'-log.txt'
    try:
        print("\n\n")
        print("Program " +str(value)+" result:")
        with open(file_name) as actual_file, open("./reference/"+file_name) as reference_file:
            actual_file_success_line = ""
            actual_file_flag = 0
            for line in actual_file:
                if actual_file_flag ==0:
                    actual_file_success_line = line
                    actual_file_flag = 1
                if "success" in line:
                    actual_file_success_line = line


            reference_file_flag = 0
            reference_file_success_line = ""
            for line in reference_file:
                if reference_file_flag==0:
                    reference_file_success_line = line
                    reference_file_flag = 1
                if "success" in line:
                    reference_file_success_line = line

            if not actual_file_success_line or not reference_file_success_line:
                programs_mismatch.append(value)
                print("\tResults do not match with the reference results")
                continue
            actual_parsed_line = parse_line(actual_file_success_line)
            reference_parsed_line = parse_line(reference_file_success_line)

            if "success" not in actual_file_success_line:
                print("\tpLiner was unable to remove inconsistency for the file")
                pliner_isolation_failed_list.append(value)



            if (actual_parsed_line.output ==  actual_parsed_line.transformed_output) and (actual_parsed_line.output == reference_parsed_line.output) and (actual_parsed_line.transformed_output and reference_parsed_line.transformed_output):
                print("\tResults match with the reference results")
                if "success"  in actual_file_success_line:
                    print("\t\tIsolated region granularity:" +actual_parsed_line.block_type )
                for k,v in actual_parsed_line.function_dict.items():
                    print("\t\t Function Name: " + k)
                    print ("\t\t Lines isolated: " + str(v))
                programs_match.append(value)
            else:
                print("\tResults do not match")
                programs_mismatch.append(value)
    except IOError as ex:
        programs_mismatch.append(value)
        print("\tResults do not match")
        continue

print("\nResults summary")
print("Total Number of programs matched: "+str(len(programs_match)))
print("Total Number of programs which did not match: "+str(len(programs_mismatch)))

if programs_mismatch:
    print("List of programs which did not match\n{}".format(str(programs_mismatch)))
print("Total Number of programs for which pLiner was unable to remove inconsistency: "+str(len(pliner_isolation_failed_list)))
print("List of programs for which pLiner was unable to remove inconsistency\n{}".format(str(pliner_isolation_failed_list)))
