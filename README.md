This is a Solidity contract based on the verifier contract created by ZoKrates, modified to verify boolean circuit TBCS (Two-Input Boolean Circuit Satisfiability) SNARKs. 

Boolean circuit-based SNARKs use different parameters than R1CS SNARKs, which neccessitates this modified version.

This [part of libsnark](https://github.com/scipr-lab/libsnark/blob/master/libsnark/zk_proof_systems/ppzksnark/uscs_ppzksnark/uscs_ppzksnark.tcc#L447-L528) was used as a reference to create the verifier contract.
