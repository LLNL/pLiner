This folder includes, 
(1)npb-config : our configuration on NPB tests to look for compiler-induced inconsistenies
                to re-run the experiments, do "./setup.sh"

(2)npb-debug : the 3 inconsistencies we triggered by modifying the error threshold in NPB - 1)CG.B 2)SP.A 3)SP.B
               a) to re-produce the inconsistency, e.g., the inconsistency in CG.B, run
                  $cp -r CG.B CG
                  $make cg CLASS=B
                  $./bin/cg.B.x 
