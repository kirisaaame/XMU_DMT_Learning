  ; ===========================================
  ; mssachlp.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSSACHLP_INC
MSSACHLP_INC equ <1>

A_SHAFinal PROTO :DWORD,:DWORD
A_SHAInit PROTO :DWORD
A_SHAUpdate PROTO :DWORD,:DWORD,:DWORD
CBC PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
K2_quad1 PROTO :DWORD,:DWORD,:DWORD
Kadd PROTO :DWORD,:DWORD,:DWORD,:DWORD
Kdiv PROTO :DWORD,:DWORD,:DWORD,:DWORD
Kinitialize_prime PROTO :DWORD,:DWORD,:DWORD
Kiszero PROTO :DWORD,:DWORD
Kmul PROTO :DWORD,:DWORD,:DWORD,:DWORD
Kmuladd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Ksqrt PROTO :DWORD,:DWORD,:DWORD
NewGenRandom PROTO :DWORD,:DWORD,:DWORD,:DWORD
add_diff PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
compare_diff PROTO :DWORD,:DWORD,:DWORD,:DWORD
create_modulus PROTO :DWORD,:DWORD,:DWORD,:DWORD
des PROTO :DWORD,:DWORD,:DWORD,:DWORD
deskey PROTO :DWORD,:DWORD
divide PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
divide_precondition_1 PROTO :DWORD,:DWORD,:DWORD
ec_initialize PROTO :DWORD,:DWORD,:DWORD,:DWORD
ecaffine_addition PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ecaffine_exponentiation_tabular PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ecaffine_is_infinite PROTO :DWORD,:DWORD
ecaffine_on_curve PROTO :DWORD,:DWORD
ecaffine_table_construction PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
from_modular PROTO :DWORD,:DWORD,:DWORD
mp_alloc_temp PROTO :DWORD
mp_free_temp PROTO :DWORD
mp_gcdex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mp_initialization PROTO 
mp_significant_bit_count PROTO :DWORD,:DWORD
multiply PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
random_bytes PROTO :DWORD,:DWORD
random_mod_nonzero PROTO :DWORD,:DWORD,:DWORD
rc4 PROTO :DWORD,:DWORD,:DWORD
rc4_key PROTO :DWORD,:DWORD,:DWORD
to_modular PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mssachlp.inc
echo -----------------------------------------
ENDIF
