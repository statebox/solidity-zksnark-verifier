#include <fstream>

#include "libsnark/zk_proof_systems/ppzksnark/tbcs_ppzksnark/tbcs_ppzksnark.hpp"
#include "libff/algebra/curves/public_params.hpp"

using namespace libsnark;
using namespace libff;
using namespace std;

template<typename ppT>
void print_vk_to_file(tbcs_ppzksnark_verification_key<ppT> vk, string pathToFile)
{
  ofstream vk_data;
  vk_data.open(pathToFile);

  G2<ppT> tilde(vk.tilde_g2);
  tilde.to_affine_coordinates();

  G2<ppT> alpha_tilde(vk.alpha_tilde_g2);
  alpha_tilde.to_affine_coordinates();

  G2<ppT> Z(vk.Z_g2);
  Z.to_affine_coordinates();

  accumulation_vector<G1<ppT>> IC(vk.encoded_IC_query);
  G1<ppT> IC_0(IC.first);
  IC_0.to_affine_coordinates();

  vk_data << tilde.X << endl;
  vk_data << tilde.Y << endl;

  vk_data << alpha_tilde.X << endl;
  vk_data << alpha_tilde.Y << endl;

  vk_data << Z.X << endl;
  vk_data << Z.Y << endl;

  vk_data << IC_0.X << endl;
  vk_data << IC_0.Y << endl;

  for(size_t i=0; i<IC.size(); i++) {
    G1<ppT> IC_N(IC.rest[i]);
    IC_N.to_affine_coordinates();
    vk_data << IC_N.X << endl;
    vk_data << IC_N.Y << endl;
  }

  vk_data.close();
}

template<typename ppT>
void print_proof_to_file(tbcs_ppzksnark_proof<ppT> proof, string pathToFile)
{
  ofstream proof_data;
  proof_data.open(pathToFile);

  G1<ppT> V_g1(proof.V_g1);
  V_g1.to_affine_coordinates();

  G1<ppT> alpha_V_g1(proof.alpha_V_g1);
  alpha_V_g1.to_affine_coordinates();

  G1<ppT> H_g1(proof.H_g1);
  H_g1.to_affine_coordinates();

  G2<ppT> V_g2(proof.V_g2);
  V_g2.to_affine_coordinates();

  proof_data << V_g1.X << endl;
  proof_data << V_g1.Y << endl;

  proof_data << alpha_V_g1.X << endl;
  proof_data << alpha_V_g1.Y << endl;

  proof_data << H_g1.X << endl;
  proof_data << H_g1.Y << endl;

  // the code below serializes the extension field coordinates in the opposite order 
  // from the typical SNARK verifier contract, i.e. libsnark uses [a, b] for a + bi
  // but the solidity contract expects [b, a]. this issue only affects elements of
  // the second group G2.

  proof_data << V_g2.X << endl;
  proof_data << V_g2.Y << endl;

  proof_data.close();
}
