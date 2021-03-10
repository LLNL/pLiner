import os
import re
import ast

programs_match = []
programs_mismatch = []
class ParsedLine:
    def __init__(self, block_type, function_dict, output, transformed_output, file_name=None):
        self.block_type = block_type.lower()
        self.function_dict = function_dict
        self.output = output
        self.transformed_output = transformed_output
        self.file_name = file_name

def parse_line(line):
    file_name = line.split("::",1)[0]
    line = line.split("::",1)[1]
    block_type = line.split(":",1)[0].strip()
    try:
        function_dict = ast.literal_eval(re.search('{(.+?)}', line).group(0))
    except Exception:
        function_dict = {}
    output = line.split(",")[-1].strip()
    transformed_output = line.split(",")[-2].strip()
    return ParsedLine(block_type, function_dict, output, transformed_output, file_name)

def parse_single_file_line(line):
    block_type = line.split(":",1)[0].strip()
    try:
        function_dict = ast.literal_eval(re.search('{(.+?)}', line).group(0))
    except Exception:
        function_dict = {}
    output = line.split(",")[-1].strip()
    transformed_output = line.split(",")[-2].strip()
    return ParsedLine(block_type, function_dict, output, transformed_output)

def compare_cg_b_program():
    file_name = "cg-log.txt"
    try:
        print("\n\n")
        print("CG.B results:")
        with open("CG/"+file_name) as actual_file, open("CG.B/"+file_name) as reference_file:
            actual_file_success_line = ""
            for line in actual_file:
                if "success" in line:
                    actual_file_success_line = line


            reference_file_success_line = ""
            for line in reference_file:
                if "success" in line:
                    reference_file_success_line = line

            if not actual_file_success_line or not reference_file_success_line:
                print("\tResults do not match")
                return
            if actual_file_success_line == reference_file_success_line:
                print("\tResults match")
                actual_parsed_line = parse_single_file_line(actual_file_success_line)
                print("\t\t Isolated region granularity: " +actual_parsed_line.block_type)
                print("\t\t Function Name: sparse")
            else:
                print("\tResults do not match")
    except Exception:
        print("\tResults do not match")
        return

def compare_sp_a_program():
    file_name = "plog.txt"
    try:
        print("\n\n")
        print("SP.A results:")
        with open("SP/"+file_name) as actual_file, open("SP.A/"+file_name) as reference_file:
            actual_file_success_line = ""
            for line in actual_file:
                if "success" in line:
                    actual_file_success_line = line


            reference_file_success_line = ""
            for line in reference_file:
                if "success" in line:
                    reference_file_success_line = line

            if not actual_file_success_line or not reference_file_success_line:
                print("\tResults do not match")
                return
            if actual_file_success_line == reference_file_success_line:
                print("\tResults match")
                actual_parsed_line = parse_line(actual_file_success_line)
                print("\t\t File Name: " + actual_parsed_line.file_name)
                print("\t\t Isolated region granularity: " +actual_parsed_line.block_type )
                for k,v in actual_parsed_line.function_dict.items():
                    print("\t\t Function Name: " + k)
                    print ("\t\t Lines isolated: " + str(v))
            else:
                print("\tResults do not match")

    except Exception:
        print("\tResults do not match")
        return

def compare_sp_b_program():
    file_name = "plog.txt"
    try:
        print("\n\n")
        print("SP.B results:")
        with open("SP_B_FINAL/"+file_name) as actual_file, open("SP.B/"+file_name) as reference_file:
            actual_file_success_line = ""
            for line in actual_file:
                if "success" in line:
                    actual_file_success_line = line


            reference_file_success_line = ""
            for line in reference_file:
                if "success" in line:
                    reference_file_success_line = line

            if not actual_file_success_line or not reference_file_success_line:
                print("\tResults do not match")
                return
            if actual_file_success_line == reference_file_success_line:
                actual_parsed_line = parse_line(actual_file_success_line)
                print("\tResults match")
                
                #reference_parsed_line = parse_line(reference_file_success_line)
                print("\t\t File Name: " + actual_parsed_line.file_name)
                print("\t\t Isolated region granularity: " +actual_parsed_line.block_type )
                for k,v in actual_parsed_line.function_dict.items():
                    print("\t\t Function Name: " + k)
                    print ("\t\t Lines isolated: " + str(v))
            else:
                print("\tResults do not match")

    except Exception:
        print("\tResults do not match")
        return



compare_cg_b_program()
compare_sp_a_program()
compare_sp_b_program()
