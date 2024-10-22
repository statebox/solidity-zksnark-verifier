This repo containts a Solidity contract based on the verifier contract created by ZoKrates, modified to verify boolean circuit TBCS (Two-Input Boolean Circuit Satisfiability) SNARKs. It also contains a second contract with a verifying key and proof hardcoded into the contract. The verifying key and proof were generated by libsnark from [prime_under_16](https://github.com/statebox/libsnark-circuit/blob/master/src/prime_under_16.cpp).

Boolean circuit-based SNARKs use different parameters than R1CS SNARKs, which neccessitates this modified version.

This [part of libsnark](https://github.com/scipr-lab/libsnark/blob/master/libsnark/zk_proof_systems/ppzksnark/uscs_ppzksnark/uscs_ppzksnark.tcc#L447-L528) was used as a reference to create the verifier contract.

## Running a Contract
The Solidity contracts in this file can be run using the [Remix IDE](remix.ethereum.org), [truffle.js](https://github.com/trufflesuite/truffle), or [web3.js](https://github.com/ethereum/web3.js/).

### Running the hardcoded verifier with Remix IDE
The [hardcoded_tbcs_verifer.sol](hardcoded_tbcs_verifer.sol) contract can be run as-is on Remix IDE. 

- First open the contract in Remix. 
- Compile the code with the 0.5.11 version of the Solidity compiler.
- Deploy each of the three functions found in the contract: `BN256G2`, `Pairing`, and `Verifier`.
- Once each has been deployed, simply run the `verifiyTx` function with no input data.

### Running the general conract with Remix IDE

The general contract [tbcs_verifer.sol](tbcs_verifer.sol) can also run in Remix.

- First, get a verifying key and proof in JSON form. You can do this by running the `prime_under_16` binary from the [libsnark-circuit](https://github.com/statebox/libsnark-circuit) repo, or you can you use the example data provided in [vk.json] and [proof.json] included in the repo.
- Open the contract in Remix. 
- Compile the contract using the 0.5.11 version of Solidity. 
- Deploy each of the three functions in the contract : BN256G2, Pairing, and Verifier. 
- Then run the `setVerifyingKey` function with the `vk.json` data as input. 
- Then run the `verifyTx` function with the `proof.json` data as input.
