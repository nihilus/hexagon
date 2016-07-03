HEXAGON_OPCODE ("Cd32 = Rs32"                            , "0110 0010  001sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* A2_tfrrcr */
HEXAGON_OPCODE ("Cdd32 = Rss32"                          , "0110 0011  001sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* A4_tfrpcp */
HEXAGON_OPCODE ("Gd32 = Rs32"                            , "0110 0010  000sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* G4_tfrgrcr */
HEXAGON_OPCODE ("Gdd32 = Rss32"                          , "0110 0011  000sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* G4_tfrgpcp */
HEXAGON_OPCODE ("Pd4 = ! bitsclr ( Rs32 , #u6 )"         , "10000101 101sssss PPiiiiii ------dd"        , 0xc, 0, 0) /* C4_nbitsclri */
HEXAGON_OPCODE ("Pd4 = ! bitsclr ( Rs32 , Rt32 )"        , "1100 0111  101sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* C4_nbitsclr */
HEXAGON_OPCODE ("Pd4 = ! bitsset ( Rs32 , Rt32 )"        , "1100 0111  011sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* C4_nbitsset */
HEXAGON_OPCODE ("Pd4 = ! cmp.eq ( Rs32 , #s10 )"         , "0111 0101 00isssss PPiiiiii iii100dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C4_cmpneqi */
HEXAGON_OPCODE ("Pd4 = ! cmp.eq ( Rs32 , Rt32 )"         , "1111 0010  -00sssss  PP-ttttt ---100dd"     , 0xf, 0, 0) /* C4_cmpneq */
HEXAGON_OPCODE ("Pd4 = ! cmp.gt ( Rs32 , #s10 )"         , "0111 0101 01isssss PPiiiiii iii100dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C4_cmpltei */
HEXAGON_OPCODE ("Pd4 = ! cmp.gt ( Rs32 , Rt32 )"         , "1111 0010  -10sssss  PP-ttttt ---100dd"     , 0xf, 0, 0) /* C4_cmplte */
HEXAGON_OPCODE ("Pd4 = ! cmp.gtu ( Rs32 , #u9 )"         , "0111 0101 100sssss PPiiiiii iii100dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C4_cmplteui */
HEXAGON_OPCODE ("Pd4 = ! cmp.gtu ( Rs32 , Rt32 )"        , "1111 0010  -11sssss  PP-ttttt ---100dd"     , 0xf, 0, 0) /* C4_cmplteu */
HEXAGON_OPCODE ("Pd4 = ! fastcorner9 ( Ps4 , Pt4 )"      , "01101011 0001--ss  PP1---tt 1--1--dd"       , 0xc, 0, 0) /* C4_fastcorner9_not */
HEXAGON_OPCODE ("Pd4 = ! tstbit ( Rs32 , #u5 )"          , "10000101 001sssss PP0iiiii ------dd"        , 0xc, 0, 0) /* S4_ntstbit_i */
HEXAGON_OPCODE ("Pd4 = ! tstbit ( Rs32 , Rt32 )"         , "1100 0111  001sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* S4_ntstbit_r */
HEXAGON_MAPPING ("Pd4 = Ps4"                              , "0000ddss000000000000000000000000"           , HEXAGON_MAP_FNAME(C2_pxfer_map)) /* mapped to Pd4=or(Ps4,Ps4) */
HEXAGON_OPCODE ("Pd4 = Rs32"                             , "1000 0101 010sssss PP------ ------dd"       , 0xc, 0, 0) /* C2_tfrrp */
HEXAGON_OPCODE ("Pd4 = all8 ( Ps4 )"                     , "0110 1011  1010--ss  PP0-----  ------dd"    , 0xc, 0, 0) /* C2_all8 */
HEXAGON_OPCODE ("Pd4 = and ( Ps4 , and ( Pt4 , ! Pu4 ) )" , "0110 1011  1001--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_and_andn */
HEXAGON_OPCODE ("Pd4 = and ( Ps4 , and ( Pt4 , Pu4 ) )"  , "0110 1011  0001--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_and_and */
HEXAGON_OPCODE ("Pd4 = and ( Ps4 , or ( Pt4 , ! Pu4 ) )" , "0110 1011  1011--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_and_orn */
HEXAGON_OPCODE ("Pd4 = and ( Ps4 , or ( Pt4 , Pu4 ) )"   , "0110 1011  0011--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_and_or */
HEXAGON_OPCODE ("Pd4 = and ( Pt4 , ! Ps4 )"              , "0110 1011  0110--ss  PP0---tt  ------dd"    , 0xc, 0, 0) /* C2_andn */
HEXAGON_OPCODE ("Pd4 = and ( Pt4 , Ps4 )"                , "0110 1011  0000--ss  PP0---tt  ------dd"    , 0xc, 0, 0) /* C2_and */
HEXAGON_OPCODE ("Pd4 = any8 ( Ps4 )"                     , "0110 1011  1000--ss  PP0-----  ------dd"    , 0xc, 0, 0) /* C2_any8 */
HEXAGON_OPCODE ("Pd4 = any8 ( vcmpb.eq ( Rss32 , Rtt32 ) )" , "1101 0010  0--sssss  PP1ttttt 000---dd"     , 0xc, 0, 0) /* A4_vcmpbeq_any */
HEXAGON_OPCODE ("Pd4 = bitsclr ( Rs32 , #u6 )"           , "1000 0101 100sssss PPiiiiii ------dd"       , 0xc, 0, 0) /* C2_bitsclri */
HEXAGON_OPCODE ("Pd4 = bitsclr ( Rs32 , Rt32 )"          , "1100 0111  100sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* C2_bitsclr */
HEXAGON_OPCODE ("Pd4 = bitsset ( Rs32 , Rt32 )"          , "1100 0111  010sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* C2_bitsset */
HEXAGON_MAPPING ("Pd4 = boundscheck ( Rs32 , Rtt32 )"     , "0000ddsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(A4_boundscheck)) /* mapped to Pd4=boundscheck(Rss32,Rtt32):raw:hi or Pd4=boundscheck(Rss32,Rtt32):raw:lo */
HEXAGON_OPCODE ("Pd4 = boundscheck ( Rss32 , Rtt32 ) :raw :hi" , "1101 0010  0--sssss  PP1ttttt 101---dd"     , 0xc, 0, 0) /* A4_boundscheck_hi */
HEXAGON_OPCODE ("Pd4 = boundscheck ( Rss32 , Rtt32 ) :raw :lo" , "1101 0010  0--sssss  PP1ttttt 100---dd"     , 0xc, 0, 0) /* A4_boundscheck_lo */
HEXAGON_OPCODE ("Pd4 = cmp.eq ( Rs32 , #s10 )"           , "0111 0101 00isssss PPiiiiii iii000dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_cmpeqi */
HEXAGON_OPCODE ("Pd4 = cmp.eq ( Rs32 , Rt32 )"           , "1111 0010  -00sssss  PP-ttttt ---000dd"     , 0xf, 0, 0) /* C2_cmpeq */
HEXAGON_OPCODE ("Pd4 = cmp.eq ( Rss32 , Rtt32 )"         , "1101 0010  100sssss  PP-ttttt 000---dd"     , 0xc, 0, 0) /* C2_cmpeqp */
HEXAGON_MAPPING ("Pd4 = cmp.ge ( Rs32 , #s8 )"            , "0000ddsssssiiiiiiii0000000000000"           , HEXAGON_MAP_FNAME(C2_cmpgei)) /* mapped to Pd4=cmp.gt(Rs32,#s8-1) */
HEXAGON_MAPPING ("Pd4 = cmp.geu ( Rs32 , #u8 )"           , "0000ddsssssiiiiiiii0000000000000"           , HEXAGON_MAP_FNAME(C2_cmpgeui)) /* mapped to Pd4=cmp.eq(Rs32,Rs32) or Pd4=cmp.gtu(Rs32,#u8-1) */
HEXAGON_OPCODE ("Pd4 = cmp.gt ( Rs32 , #s10 )"           , "0111 0101 01isssss PPiiiiii iii000dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_cmpgti */
HEXAGON_OPCODE ("Pd4 = cmp.gt ( Rs32 , Rt32 )"           , "1111 0010  -10sssss  PP-ttttt ---000dd"     , 0xf, 0, 0) /* C2_cmpgt */
HEXAGON_OPCODE ("Pd4 = cmp.gt ( Rss32 , Rtt32 )"         , "1101 0010  100sssss  PP-ttttt 010---dd"     , 0xc, 0, 0) /* C2_cmpgtp */
HEXAGON_OPCODE ("Pd4 = cmp.gtu ( Rs32 , #u9 )"           , "0111 0101 100sssss PPiiiiii iii000dd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_cmpgtui */
HEXAGON_OPCODE ("Pd4 = cmp.gtu ( Rs32 , Rt32 )"          , "1111 0010  -11sssss  PP-ttttt ---000dd"     , 0xf, 0, 0) /* C2_cmpgtu */
HEXAGON_OPCODE ("Pd4 = cmp.gtu ( Rss32 , Rtt32 )"        , "1101 0010  100sssss  PP-ttttt 100---dd"     , 0xc, 0, 0) /* C2_cmpgtup */
HEXAGON_MAPPING ("Pd4 = cmp.lt ( Rs32 , Rt32 )"           , "0000ddsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(C2_cmplt)) /* mapped to Pd4=cmp.gt(Rt32,Rs32) */
HEXAGON_MAPPING ("Pd4 = cmp.ltu ( Rs32 , Rt32 )"          , "0000ddsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(C2_cmpltu)) /* mapped to Pd4=cmp.gtu(Rt32,Rs32) */
HEXAGON_OPCODE ("Pd4 = cmpb.eq ( Rs32 , #u8 )"           , "11011101 -00sssss PP-iiiii iii00-dd"        , 0xc, 0, 0) /* A4_cmpbeqi */
HEXAGON_OPCODE ("Pd4 = cmpb.eq ( Rs32 , Rt32 )"          , "1100 0111  110sssss  PP-ttttt 110---dd"     , 0xc, 0, 0) /* A4_cmpbeq */
HEXAGON_OPCODE ("Pd4 = cmpb.gt ( Rs32 , #s8 )"           , "11011101 -01sssss PP-iiiii iii00-dd"        , 0xc, 0, 0) /* A4_cmpbgti */
HEXAGON_OPCODE ("Pd4 = cmpb.gt ( Rs32 , Rt32 )"          , "1100 0111  110sssss  PP-ttttt 010---dd"     , 0xc, 0, 0) /* A4_cmpbgt */
HEXAGON_OPCODE ("Pd4 = cmpb.gtu ( Rs32 , #u7 )"          , "11011101 -10sssss PP-0iiii iii00-dd"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_cmpbgtui */
HEXAGON_OPCODE ("Pd4 = cmpb.gtu ( Rs32 , Rt32 )"         , "1100 0111  110sssss  PP-ttttt 111---dd"     , 0xc, 0, 0) /* A4_cmpbgtu */
HEXAGON_OPCODE ("Pd4 = cmph.eq ( Rs32 , #s8 )"           , "11011101 -00sssss PP-iiiii iii01-dd"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_cmpheqi */
HEXAGON_OPCODE ("Pd4 = cmph.eq ( Rs32 , Rt32 )"          , "1100 0111  110sssss  PP-ttttt 011---dd"     , 0xc, 0, 0) /* A4_cmpheq */
HEXAGON_OPCODE ("Pd4 = cmph.gt ( Rs32 , #s8 )"           , "11011101 -01sssss PP-iiiii iii01-dd"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_cmphgti */
HEXAGON_OPCODE ("Pd4 = cmph.gt ( Rs32 , Rt32 )"          , "1100 0111  110sssss  PP-ttttt 100---dd"     , 0xc, 0, 0) /* A4_cmphgt */
HEXAGON_OPCODE ("Pd4 = cmph.gtu ( Rs32 , #u7 )"          , "11011101 -10sssss PP-0iiii iii01-dd"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_cmphgtui */
HEXAGON_OPCODE ("Pd4 = cmph.gtu ( Rs32 , Rt32 )"         , "1100 0111  110sssss  PP-ttttt 101---dd"     , 0xc, 0, 0) /* A4_cmphgtu */
HEXAGON_OPCODE ("Pd4 = dfclass ( Rss32 , #u5 )"          , "11011100 100sssss PP-000ii iii10-dd"        , 0xc, 0, 0|A_CONDEXEC|A_XFLOAT) /* F2_dfclass */
HEXAGON_OPCODE ("Pd4 = dfcmp.eq ( Rss32 , Rtt32 )"       , "1101 0010  111sssss  PP-ttttt 000---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_dfcmpeq */
HEXAGON_OPCODE ("Pd4 = dfcmp.ge ( Rss32 , Rtt32 )"       , "1101 0010  111sssss  PP-ttttt 010---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_dfcmpge */
HEXAGON_OPCODE ("Pd4 = dfcmp.gt ( Rss32 , Rtt32 )"       , "1101 0010  111sssss  PP-ttttt 001---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_dfcmpgt */
HEXAGON_OPCODE ("Pd4 = dfcmp.uo ( Rss32 , Rtt32 )"       , "1101 0010  111sssss  PP-ttttt 011---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_dfcmpuo */
HEXAGON_OPCODE ("Pd4 = fastcorner9 ( Ps4 , Pt4 )"        , "01101011 0000--ss  PP1---tt 1--1--dd"       , 0xc, 0, 0) /* C4_fastcorner9 */
HEXAGON_OPCODE ("Pd4 = not ( Ps4 )"                      , "0110 1011  1100--ss  PP0-----  ------dd"    , 0xc, 0, 0) /* C2_not */
HEXAGON_OPCODE ("Pd4 = or ( Ps4 , and ( Pt4 , ! Pu4 ) )" , "0110 1011  1101--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_or_andn */
HEXAGON_OPCODE ("Pd4 = or ( Ps4 , and ( Pt4 , Pu4 ) )"   , "0110 1011  0101--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_or_and */
HEXAGON_OPCODE ("Pd4 = or ( Ps4 , or ( Pt4 , ! Pu4 ) )"  , "0110 1011  1111--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_or_orn */
HEXAGON_OPCODE ("Pd4 = or ( Ps4 , or ( Pt4 , Pu4 ) )"    , "0110 1011  0111--ss  PP0---tt  uu----dd"    , 0xc, 0, 0) /* C4_or_or */
HEXAGON_OPCODE ("Pd4 = or ( Pt4 , ! Ps4 )"               , "0110 1011  1110--ss  PP0---tt  ------dd"    , 0xc, 0, 0) /* C2_orn */
HEXAGON_OPCODE ("Pd4 = or ( Pt4 , Ps4 )"                 , "0110 1011  0010--ss  PP0---tt  ------dd"    , 0xc, 0, 0) /* C2_or */
HEXAGON_OPCODE ("Pd4 = sfclass ( Rs32 , #u5 )"           , "10000101 111sssss PP0iiiii ------dd"        , 0xc, 0, 0|A_CONDEXEC|A_XFLOAT) /* F2_sfclass */
HEXAGON_OPCODE ("Pd4 = sfcmp.eq ( Rs32 , Rt32 )"         , "1100 0111  111sssss  PP-ttttt 011---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sfcmpeq */
HEXAGON_OPCODE ("Pd4 = sfcmp.ge ( Rs32 , Rt32 )"         , "1100 0111  111sssss  PP-ttttt 000---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sfcmpge */
HEXAGON_OPCODE ("Pd4 = sfcmp.gt ( Rs32 , Rt32 )"         , "1100 0111  111sssss  PP-ttttt 100---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sfcmpgt */
HEXAGON_OPCODE ("Pd4 = sfcmp.uo ( Rs32 , Rt32 )"         , "1100 0111  111sssss  PP-ttttt 001---dd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sfcmpuo */
HEXAGON_OPCODE ("Pd4 = tlbmatch ( Rss32 , Rt32 )"        , "1101 0010  0--sssss  PP1ttttt 011---dd"     , 0xc, 0, 0|A_LATEPRED) /* A4_tlbmatch */
HEXAGON_OPCODE ("Pd4 = tstbit ( Rs32 , #u5 )"            , "1000 0101 000sssss PP0iiiii ------dd"       , 0xc, 0, 0) /* S2_tstbit_i */
HEXAGON_OPCODE ("Pd4 = tstbit ( Rs32 , Rt32 )"           , "1100 0111  000sssss  PP-ttttt ------dd"     , 0xc, 0, 0) /* S2_tstbit_r */
HEXAGON_OPCODE ("Pd4 = vcmpb.eq ( Rss32 , #u8 )"         , "11011100 000sssss PP-iiiii iii00-dd"        , 0xc, 0, 0) /* A4_vcmpbeqi */
HEXAGON_OPCODE ("Pd4 = vcmpb.eq ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP0ttttt 110---dd"     , 0xc, 0, 0) /* A2_vcmpbeq */
HEXAGON_OPCODE ("Pd4 = vcmpb.gt ( Rss32 , #s8 )"         , "11011100 001sssss PP-iiiii iii00-dd"        , 0xc, 0, 0) /* A4_vcmpbgti */
HEXAGON_OPCODE ("Pd4 = vcmpb.gt ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP1ttttt 010---dd"     , 0xc, 0, 0) /* A4_vcmpbgt */
HEXAGON_OPCODE ("Pd4 = vcmpb.gtu ( Rss32 , #u7 )"        , "11011100 010sssss PP-0iiii iii00-dd"        , 0xc, 0, 0) /* A4_vcmpbgtui */
HEXAGON_OPCODE ("Pd4 = vcmpb.gtu ( Rss32 , Rtt32 )"      , "1101 0010  0--sssss  PP0ttttt 111---dd"     , 0xc, 0, 0) /* A2_vcmpbgtu */
HEXAGON_OPCODE ("Pd4 = vcmph.eq ( Rss32 , #s8 )"         , "11011100 000sssss PP-iiiii iii01-dd"        , 0xc, 0, 0) /* A4_vcmpheqi */
HEXAGON_OPCODE ("Pd4 = vcmph.eq ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP0ttttt 011---dd"     , 0xc, 0, 0) /* A2_vcmpheq */
HEXAGON_OPCODE ("Pd4 = vcmph.gt ( Rss32 , #s8 )"         , "11011100 001sssss PP-iiiii iii01-dd"        , 0xc, 0, 0) /* A4_vcmphgti */
HEXAGON_OPCODE ("Pd4 = vcmph.gt ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP0ttttt 100---dd"     , 0xc, 0, 0) /* A2_vcmphgt */
HEXAGON_OPCODE ("Pd4 = vcmph.gtu ( Rss32 , #u7 )"        , "11011100 010sssss PP-0iiii iii01-dd"        , 0xc, 0, 0) /* A4_vcmphgtui */
HEXAGON_OPCODE ("Pd4 = vcmph.gtu ( Rss32 , Rtt32 )"      , "1101 0010  0--sssss  PP0ttttt 101---dd"     , 0xc, 0, 0) /* A2_vcmphgtu */
HEXAGON_OPCODE ("Pd4 = vcmpw.eq ( Rss32 , #s8 )"         , "11011100 000sssss PP-iiiii iii10-dd"        , 0xc, 0, 0) /* A4_vcmpweqi */
HEXAGON_OPCODE ("Pd4 = vcmpw.eq ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP0ttttt 000---dd"     , 0xc, 0, 0) /* A2_vcmpweq */
HEXAGON_OPCODE ("Pd4 = vcmpw.gt ( Rss32 , #s8 )"         , "11011100 001sssss PP-iiiii iii10-dd"        , 0xc, 0, 0) /* A4_vcmpwgti */
HEXAGON_OPCODE ("Pd4 = vcmpw.gt ( Rss32 , Rtt32 )"       , "1101 0010  0--sssss  PP0ttttt 001---dd"     , 0xc, 0, 0) /* A2_vcmpwgt */
HEXAGON_OPCODE ("Pd4 = vcmpw.gtu ( Rss32 , #u7 )"        , "11011100 010sssss PP-0iiii iii10-dd"        , 0xc, 0, 0) /* A4_vcmpwgtui */
HEXAGON_OPCODE ("Pd4 = vcmpw.gtu ( Rss32 , Rtt32 )"      , "1101 0010  0--sssss  PP0ttttt 010---dd"     , 0xc, 0, 0) /* A2_vcmpwgtu */
HEXAGON_OPCODE ("Pd4 = xor ( Ps4 , Pt4 )"                , "0110 1011  0100--ss  PP0---tt  ------dd"    , 0xc, 0, 0) /* C2_xor */
HEXAGON_OPCODE ("Rd16 = #-1 ; allocframe ( #u5:3 )"      , "0111101--0--ddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = #-1 ; dealloc_return"            , "0101101--0--ddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_setin1_SL2_return */
HEXAGON_OPCODE ("Rd16 = #-1 ; deallocframe"              , "0101101--0--ddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( ! p0 ) dealloc_return" , "0101101--0--ddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_setin1_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( ! p0 ) jumpr Lr"      , "0101101--0--ddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( ! p0 .new ) dealloc_return:nt" , "0101101--0--ddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_setin1_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( ! p0 .new ) jumpr:nt Lr" , "0101101--0--ddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( p0 ) dealloc_return"  , "0101101--0--ddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_setin1_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( p0 ) jumpr Lr"        , "0101101--0--ddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( p0 .new ) dealloc_return:nt" , "0101101--0--ddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_setin1_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = #-1 ; if ( p0 .new ) jumpr:nt Lr" , "0101101--0--ddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = #-1 ; jumpr Lr"                  , "0101101--0--ddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = #-1 ; memb ( Rs16 + #u4:0 ) = #0" , "0111101--0--ddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = #-1 ; memb ( Rs16 + #u4:0 ) = #1" , "0111101--0--ddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = #-1 ; memb ( Rs16 + #u4:0 ) = Rt16" , "0111101--0--ddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = #-1 ; memd ( Sp + #s6:3 ) = Rtt8" , "0111101--0--ddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = #-1 ; memh ( Rs16 + #u3:1 ) = Rt16" , "0111101--0--ddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = #-1 ; memw ( Rs16 + #u4:2 ) = #0" , "0111101--0--ddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = #-1 ; memw ( Rs16 + #u4:2 ) = #1" , "0111101--0--ddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = #-1 ; memw ( Rs16 + #u4:2 ) = Rt16" , "0111101--0--ddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = #-1 ; memw ( Sp + #u5:2 ) = Rt16" , "0111101--0--ddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = #U6 ; allocframe ( #u5:3 )"      , "011010IIIIIIddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = #U6 ; jump #r9:2"                , "0001 -110  --iidddd  PPIIIIII  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_jumpseti */
HEXAGON_OPCODE ("Rd16 = #U6 ; memb ( Rs16 + #u4:0 ) = #0" , "011010IIIIIIddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = #U6 ; memb ( Rs16 + #u4:0 ) = #1" , "011010IIIIIIddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = #U6 ; memb ( Rs16 + #u4:0 ) = Rt16" , "011010IIIIIIddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = #U6 ; memd ( Sp + #s6:3 ) = Rtt8" , "011010IIIIIIddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = #U6 ; memh ( Rs16 + #u3:1 ) = Rt16" , "011010IIIIIIddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = #U6 ; memw ( Rs16 + #u4:2 ) = #0" , "011010IIIIIIddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = #U6 ; memw ( Rs16 + #u4:2 ) = #1" , "011010IIIIIIddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = #U6 ; memw ( Rs16 + #u4:2 ) = Rt16" , "011010IIIIIIddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = #U6 ; memw ( Sp + #u5:2 ) = Rt16" , "011010IIIIIIddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = #U6 ; p0 = cmp.eq ( Rs16 , #u2 )" , "001010IIIIIIddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = #u6 ; Rx16 = add ( Rs16 , Rx16 )" , "001010iiiiiiddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = #u6 ; Rx16 = add ( Rx16 , Rs16 )" , "001010iiiiiiddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = #u6 ; dealloc_return"            , "010010iiiiiiddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_seti_SL2_return */
HEXAGON_OPCODE ("Rd16 = #u6 ; deallocframe"              , "010010iiiiiiddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( ! p0 ) dealloc_return" , "010010iiiiiiddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_seti_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( ! p0 ) jumpr Lr"      , "010010iiiiiiddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( ! p0 .new ) dealloc_return:nt" , "010010iiiiiiddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_seti_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( ! p0 .new ) jumpr:nt Lr" , "010010iiiiiiddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( p0 ) dealloc_return"  , "010010iiiiiiddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_seti_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( p0 ) jumpr Lr"        , "010010iiiiiiddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( p0 .new ) dealloc_return:nt" , "010010iiiiiiddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_seti_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = #u6 ; if ( p0 .new ) jumpr:nt Lr" , "010010iiiiiiddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = #u6 ; jumpr Lr"                  , "010010iiiiiiddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = Rs16 ; allocframe ( #u5:3 )"     , "01110000ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = Rs16 ; dealloc_return"           , "01010000ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_tfr_SL2_return */
HEXAGON_OPCODE ("Rd16 = Rs16 ; deallocframe"             , "01010000ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( ! p0 ) dealloc_return" , "01010000ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_tfr_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( ! p0 ) jumpr Lr"     , "01010000ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( ! p0 .new ) dealloc_return:nt" , "01010000ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_tfr_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( ! p0 .new ) jumpr:nt Lr" , "01010000ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( p0 ) dealloc_return" , "01010000ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_tfr_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( p0 ) jumpr Lr"       , "01010000ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( p0 .new ) dealloc_return:nt" , "01010000ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_tfr_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = Rs16 ; if ( p0 .new ) jumpr:nt Lr" , "01010000ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = Rs16 ; jump #r9:2"               , "0001 -111  --iissss  PP--dddd  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_jumpsetr */
HEXAGON_OPCODE ("Rd16 = Rs16 ; jumpr Lr"                 , "01010000ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = Rs16 ; memd ( Sp + #s6:3 ) = Rtt8" , "01110000ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = Rs16 ; memw ( Sp + #u5:2 ) = Rt16" , "01110000ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = Ru16 ; Rx16 = add ( Rs16 , Rx16 )" , "00110000uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = Ru16 ; Rx16 = add ( Rx16 , Rs16 )" , "00110000uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memb ( Rs16 + #u4:0 ) = #0" , "01110000uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memb ( Rs16 + #u4:0 ) = #1" , "01110000uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110000uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110000uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memw ( Rs16 + #u4:2 ) = #0" , "01110000uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memw ( Rs16 + #u4:2 ) = #1" , "01110000uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = Ru16 ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110000uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = Ru16 ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110000uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; allocframe ( #u5:3 )" , "01110011ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; dealloc_return" , "01010011ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_dec_SL2_return */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; deallocframe" , "01010011ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( ! p0 ) dealloc_return" , "01010011ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_dec_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( ! p0 ) jumpr Lr" , "01010011ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010011ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_dec_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010011ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( p0 ) dealloc_return" , "01010011ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_dec_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( p0 ) jumpr Lr" , "01010011ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( p0 .new ) dealloc_return:nt" , "01010011ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_dec_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010011ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; jumpr Lr"   , "01010011ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110011ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #-1 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110011ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; allocframe ( #u5:3 )" , "01110001ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; dealloc_return" , "01010001ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_inc_SL2_return */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; deallocframe" , "01010001ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( ! p0 ) dealloc_return" , "01010001ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_inc_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( ! p0 ) jumpr Lr" , "01010001ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010001ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_inc_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010001ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( p0 ) dealloc_return" , "01010001ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_inc_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( p0 ) jumpr Lr" , "01010001ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( p0 .new ) dealloc_return:nt" , "01010001ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_inc_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010001ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; jumpr Lr"    , "01010001ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110001ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = add ( Rs16 , #1 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110001ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110011uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110011uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110011uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110011uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110011uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110011uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110011uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110011uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110011uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #-1 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110011uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110001uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110001uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110001uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110001uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110001uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110001uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110001uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110001uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110001uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = add ( Ru16 , #1 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110001uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; allocframe ( #u5:3 )" , "011011IIIIIIddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011011IIIIIIddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011011IIIIIIddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011011IIIIIIddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011011IIIIIIddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011011IIIIIIddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011011IIIIIIddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011011IIIIIIddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011011IIIIIIddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011011IIIIIIddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #U6:2 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "001011IIIIIIddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; Rx16 = add ( Rs16 , Rx16 )" , "001011iiiiiiddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; Rx16 = add ( Rx16 , Rs16 )" , "001011iiiiiiddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; dealloc_return" , "010011iiiiiiddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addsp_SL2_return */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; deallocframe" , "010011iiiiiiddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( ! p0 ) dealloc_return" , "010011iiiiiiddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addsp_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( ! p0 ) jumpr Lr" , "010011iiiiiiddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010011iiiiiiddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addsp_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010011iiiiiiddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( p0 ) dealloc_return" , "010011iiiiiiddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addsp_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( p0 ) jumpr Lr" , "010011iiiiiiddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( p0 .new ) dealloc_return:nt" , "010011iiiiiiddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addsp_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; if ( p0 .new ) jumpr:nt Lr" , "010011iiiiiiddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = add ( Sp , #u6:2 ) ; jumpr Lr"   , "010011iiiiiiddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; allocframe ( #u5:3 )" , "01110010ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; dealloc_return" , "01010010ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_and1_SL2_return */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; deallocframe" , "01010010ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( ! p0 ) dealloc_return" , "01010010ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_and1_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( ! p0 ) jumpr Lr" , "01010010ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010010ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_and1_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010010ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( p0 ) dealloc_return" , "01010010ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_and1_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( p0 ) jumpr Lr" , "01010010ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( p0 .new ) dealloc_return:nt" , "01010010ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_and1_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010010ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; jumpr Lr"    , "01010010ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110010ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #1 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110010ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; allocframe ( #u5:3 )" , "01110111ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; dealloc_return" , "01010111ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxtb_SL2_return */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; deallocframe" , "01010111ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( ! p0 ) dealloc_return" , "01010111ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxtb_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( ! p0 ) jumpr Lr" , "01010111ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010111ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxtb_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010111ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( p0 ) dealloc_return" , "01010111ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxtb_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( p0 ) jumpr Lr" , "01010111ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( p0 .new ) dealloc_return:nt" , "01010111ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxtb_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010111ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; jumpr Lr"  , "01010111ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110111ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = and ( Rs16 , #255 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110111ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110010uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110010uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110010uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110010uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110010uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110010uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110010uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110010uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110010uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #1 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110010uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110111uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110111uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110111uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110111uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110111uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110111uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110111uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110111uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110111uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = and ( Ru16 , #255 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110111uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #U3:0 ) ; allocframe ( #u5:3 )" , "11010IIIssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #U3:0 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "11010IIIssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #U3:0 ) ; memw ( Sp + #u5:2 ) = Rt16" , "11010IIIssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; dealloc_return" , "00110iiissssddddEE01111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_return */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; deallocframe" , "00110iiissssddddEE01111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( ! p0 ) dealloc_return" , "00110iiissssddddEE01111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( ! p0 ) jumpr Lr" , "00110iiissssddddEE01111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( ! p0 .new ) dealloc_return:nt" , "00110iiissssddddEE01111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "00110iiissssddddEE01111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( p0 ) dealloc_return" , "00110iiissssddddEE01111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( p0 ) jumpr Lr" , "00110iiissssddddEE01111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( p0 .new ) dealloc_return:nt" , "00110iiissssddddEE01111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; if ( p0 .new ) jumpr:nt Lr" , "00110iiissssddddEE01111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memb ( Rs16 + #u3:0 ) ; jumpr Lr" , "00110iiissssddddEE01111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memb ( Rs16 + #u4:0 ) = #0" , "11010IIIuuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memb ( Rs16 + #u4:0 ) = #1" , "11010IIIuuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "10010IIIuuuuddddEE11iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "11010IIIuuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memw ( Rs16 + #u4:2 ) = #0" , "11010IIIuuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memw ( Rs16 + #u4:2 ) = #1" , "11010IIIuuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memb ( Ru16 + #U3:0 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "10010IIIuuuuddddEE10iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #U3:1 ) ; allocframe ( #u5:3 )" , "11000IIIssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #U3:1 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "11000IIIssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #U3:1 ) ; memw ( Sp + #u5:2 ) = Rt16" , "11000IIIssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; dealloc_return" , "00100iiissssddddEE01111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_return */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; deallocframe" , "00100iiissssddddEE01111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( ! p0 ) dealloc_return" , "00100iiissssddddEE01111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( ! p0 ) jumpr Lr" , "00100iiissssddddEE01111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( ! p0 .new ) dealloc_return:nt" , "00100iiissssddddEE01111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "00100iiissssddddEE01111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( p0 ) dealloc_return" , "00100iiissssddddEE01111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( p0 ) jumpr Lr" , "00100iiissssddddEE01111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( p0 .new ) dealloc_return:nt" , "00100iiissssddddEE01111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; if ( p0 .new ) jumpr:nt Lr" , "00100iiissssddddEE01111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memh ( Rs16 + #u3:1 ) ; jumpr Lr" , "00100iiissssddddEE01111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = #0" , "11000IIIuuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = #1" , "11000IIIuuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "10000IIIuuuuddddEE11iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "11000IIIuuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = #0" , "11000IIIuuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = #1" , "11000IIIuuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "10000IIIuuuuddddEE10iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #U4:0 ) ; allocframe ( #u5:3 )" , "1101IIIIssssddddEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #U4:0 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "1101IIIIssssddddEE00101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #U4:0 ) ; memw ( Sp + #u5:2 ) = Rt16" , "1101IIIIssssddddEE00100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; dealloc_return" , "0001iiiissssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_return */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; deallocframe" , "0001iiiissssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( ! p0 ) dealloc_return" , "0001iiiissssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( ! p0 ) jumpr Lr" , "0001iiiissssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( ! p0 .new ) dealloc_return:nt" , "0001iiiissssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "0001iiiissssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( p0 ) dealloc_return" , "0001iiiissssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( p0 ) jumpr Lr" , "0001iiiissssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( p0 .new ) dealloc_return:nt" , "0001iiiissssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; if ( p0 .new ) jumpr:nt Lr" , "0001iiiissssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memub ( Rs16 + #u4:0 ) ; jumpr Lr" , "0001iiiissssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memb ( Rs16 + #u4:0 ) = #0" , "1101IIIIuuuuddddEE010010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memb ( Rs16 + #u4:0 ) = #1" , "1101IIIIuuuuddddEE010011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "1001IIIIuuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "1101IIIIuuuuddddEE000iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memw ( Rs16 + #u4:2 ) = #0" , "1101IIIIuuuuddddEE010000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memw ( Rs16 + #u4:2 ) = #1" , "1101IIIIuuuuddddEE010001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memub ( Ru16 + #U4:0 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "1001IIIIuuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #U3:1 ) ; allocframe ( #u5:3 )" , "11001IIIssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #U3:1 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "11001IIIssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #U3:1 ) ; memw ( Sp + #u5:2 ) = Rt16" , "11001IIIssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; dealloc_return" , "00101iiissssddddEE01111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_return */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; deallocframe" , "00101iiissssddddEE01111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( ! p0 ) dealloc_return" , "00101iiissssddddEE01111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( ! p0 ) jumpr Lr" , "00101iiissssddddEE01111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( ! p0 .new ) dealloc_return:nt" , "00101iiissssddddEE01111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "00101iiissssddddEE01111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( p0 ) dealloc_return" , "00101iiissssddddEE01111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( p0 ) jumpr Lr" , "00101iiissssddddEE01111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( p0 .new ) dealloc_return:nt" , "00101iiissssddddEE01111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; if ( p0 .new ) jumpr:nt Lr" , "00101iiissssddddEE01111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memuh ( Rs16 + #u3:1 ) ; jumpr Lr" , "00101iiissssddddEE01111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = #0" , "11001IIIuuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = #1" , "11001IIIuuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "10001IIIuuuuddddEE11iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "11001IIIuuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = #0" , "11001IIIuuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = #1" , "11001IIIuuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memuh ( Ru16 + #U3:1 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "10001IIIuuuuddddEE10iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #U4:2 ) ; allocframe ( #u5:3 )" , "1100IIIIssssddddEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #U4:2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "1100IIIIssssddddEE00101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #U4:2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "1100IIIIssssddddEE00100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; dealloc_return" , "0000iiiissssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadri_io_SL2_return */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; deallocframe" , "0000iiiissssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( ! p0 ) dealloc_return" , "0000iiiissssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadri_io_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( ! p0 ) jumpr Lr" , "0000iiiissssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "0000iiiissssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadri_io_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "0000iiiissssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( p0 ) dealloc_return" , "0000iiiissssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadri_io_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( p0 ) jumpr Lr" , "0000iiiissssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( p0 .new ) dealloc_return:nt" , "0000iiiissssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL1_loadri_io_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; if ( p0 .new ) jumpr:nt Lr" , "0000iiiissssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memw ( Rs16 + #u4:2 ) ; jumpr Lr" , "0000iiiissssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "1100IIIIuuuuddddEE010010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "1100IIIIuuuuddddEE010011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "1000IIIIuuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "1100IIIIuuuuddddEE000iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "1100IIIIuuuuddddEE010000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "1100IIIIuuuuddddEE010001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memw ( Ru16 + #U4:2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "1000IIIIuuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; allocframe ( #u5:3 )" , "1101110IIIIIddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "1101110IIIIIddddEE110010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "1101110IIIIIddddEE110011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "1001110IIIIIddddEE11iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "1101110IIIIIddddEE10101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "1101110IIIIIddddEE100iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "1101110IIIIIddddEE110000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "1101110IIIIIddddEE110001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "1001110IIIIIddddEE10iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #U5:2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "1101110IIIIIddddEE10100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; dealloc_return" , "0011110iiiiiddddEE01111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_return */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; deallocframe" , "0011110iiiiiddddEE01111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( ! p0 ) dealloc_return" , "0011110iiiiiddddEE01111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( ! p0 ) jumpr Lr" , "0011110iiiiiddddEE01111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "0011110iiiiiddddEE01111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "0011110iiiiiddddEE01111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( p0 ) dealloc_return" , "0011110iiiiiddddEE01111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( p0 ) jumpr Lr" , "0011110iiiiiddddEE01111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( p0 .new ) dealloc_return:nt" , "0011110iiiiiddddEE01111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; if ( p0 .new ) jumpr:nt Lr" , "0011110iiiiiddddEE01111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = memw ( Sp + #u5:2 ) ; jumpr Lr"  , "0011110iiiiiddddEE01111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; allocframe ( #u5:3 )" , "01110101ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; dealloc_return"  , "01010101ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxtb_SL2_return */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; deallocframe"    , "01010101ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( ! p0 ) dealloc_return" , "01010101ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxtb_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( ! p0 ) jumpr Lr" , "01010101ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010101ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxtb_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010101ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( p0 ) dealloc_return" , "01010101ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxtb_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( p0 ) jumpr Lr" , "01010101ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( p0 .new ) dealloc_return:nt" , "01010101ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxtb_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010101ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; jumpr Lr"        , "01010101ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110101ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = sxtb ( Rs16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110101ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110101uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110101uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110101uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110101uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110101uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110101uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110101uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110101uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110101uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = sxtb ( Ru16 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110101uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; allocframe ( #u5:3 )" , "01110100ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; dealloc_return"  , "01010100ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxth_SL2_return */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; deallocframe"    , "01010100ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( ! p0 ) dealloc_return" , "01010100ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxth_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( ! p0 ) jumpr Lr" , "01010100ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010100ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxth_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010100ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( p0 ) dealloc_return" , "01010100ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxth_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( p0 ) jumpr Lr" , "01010100ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( p0 .new ) dealloc_return:nt" , "01010100ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_sxth_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010100ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; jumpr Lr"        , "01010100ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110100ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = sxth ( Rs16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110100ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110100uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110100uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110100uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110100uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110100uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110100uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110100uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110100uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110100uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = sxth ( Ru16 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110100uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; allocframe ( #u5:3 )" , "01110110ssssddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_allocframe */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; dealloc_return"  , "01010110ssssddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxth_SL2_return */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; deallocframe"    , "01010110ssssddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_deallocframe */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( ! p0 ) dealloc_return" , "01010110ssssddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxth_SL2_return_f */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( ! p0 ) jumpr Lr" , "01010110ssssddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01010110ssssddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxth_SL2_return_fnew */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01010110ssssddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( p0 ) dealloc_return" , "01010110ssssddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxth_SL2_return_t */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( p0 ) jumpr Lr" , "01010110ssssddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( p0 .new ) dealloc_return:nt" , "01010110ssssddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_zxth_SL2_return_tnew */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; if ( p0 .new ) jumpr:nt Lr" , "01010110ssssddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; jumpr Lr"        , "01010110ssssddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_jumpr31 */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01110110ssssddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_stored_sp */
HEXAGON_OPCODE ("Rd16 = zxth ( Rs16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01110110ssssddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storew_sp */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00110110uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_addrx_commuted */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00110110uuuuddddEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_addrx */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01110110uuuuddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storebi0 */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01110110uuuuddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storebi1 */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01110110uuuuddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS1_storeb_io */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01110110uuuuddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storeh_io */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01110110uuuuddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storewi0 */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01110110uuuuddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS2_storewi1 */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01110110uuuuddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SS1_storew_io */
HEXAGON_OPCODE ("Rd16 = zxth ( Ru16 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00110110uuuuddddEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_cmpeqi */
HEXAGON_OPCODE ("Rd32 , Pe4 = sfinvsqrta ( Rs32 )"       , "1000 1011  111sssss  PP------ 0eeddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sfinvsqrta */
HEXAGON_OPCODE ("Rd32 , Pe4 = sfrecipa ( Rs32 , Rt32 )"  , "11101011111sssss  PP0ttttt 1eeddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfrecipa */
HEXAGON_OPCODE ("Rd32 = ! cmp.eq ( Rs32 , #s8 )"         , "0111 0011 -11sssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_rcmpneqi */
HEXAGON_OPCODE ("Rd32 = ! cmp.eq ( Rs32 , Rt32 )"        , "1111 0011  011sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A4_rcmpneq */
HEXAGON_OPCODE ("Rd32 = #s16"                            , "0111 1000 ii-iiiii PPiiiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_tfrsi */
HEXAGON_OPCODE ("Rd32 = + mpyi ( Rs32 , #u8 )"           , "111000000--sssss  PP0iiiii iiiddddd"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M2_mpysip */
HEXAGON_OPCODE ("Rd32 = - mpyi ( Rs32 , #u8 )"           , "111000001--sssss  PP0iiiii iiiddddd"        , 0xc, 0, 0) /* M2_mpysin */
HEXAGON_OPCODE ("Rd32 = Cs32"                            , "0110 1010  000sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* A2_tfrcrr */
HEXAGON_OPCODE ("Rd32 = Gs32"                            , "0110 1010  001sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* G4_tfrgcrr */
HEXAGON_OPCODE ("Rd32 = Ps4"                             , "1000 1001   -1- ---ss  PP------ --- ddddd"  , 0xc, 0, 0) /* C2_tfrpr */
HEXAGON_OPCODE ("Rd32 = Rs32"                            , "0111 0000  011sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_tfr */
HEXAGON_OPCODE ("Rd32 = Ss64"                            , "0110 1110 1-ssssss PP------ ---ddddd"       , 0x8, 0, 0) /* Y2_tfrscrr */
HEXAGON_OPCODE ("Rd32 = abs ( Rs32 ) :sat"               , "1000 1100  100sssss  PP------ 1 01ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_abssat */
HEXAGON_OPCODE ("Rd32 = abs ( Rs32 )"                    , "1000 1100  100sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* A2_abs */
HEXAGON_OPCODE ("Rd32 = add ( #u6 , mpyi ( Rs32 , #U6 ) )" , "1101 1000   Iii sssss PPiddddd iiiIIIII"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M4_mpyri_addi */
HEXAGON_OPCODE ("Rd32 = add ( #u6 , mpyi ( Rs32 , Rt32 ) )" , "1101 0111   0ii sssss PPittttt iiiddddd"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M4_mpyrr_addi */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , #s16 )"             , "1011  iiii iiisssss PPiiiiii iiiddddd"      , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_addi */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , Rt32 ) :sat :deprecated" , "1101 0101  100sssss  PP-ttttt 0--ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* dep_A2_addsat */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , Rt32 ) :sat"        , "1111 0110  010sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_addsat */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , Rt32 )"             , "1111 0011  000sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_add */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , add ( Ru32 , #s6 ) )" , "1101 1011   0ii sssss PPiddddd iiiuuuuu"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_addaddi */
HEXAGON_OPCODE ("Rd32 = add ( Rs32 , sub ( #s6 , Ru32 ) )" , "1101 1011   1ii sssss PPiddddd iiiuuuuu"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_subaddi */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.h , Rs32.h ) :<<16"   , "1101 0101  010sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_addh_h16_hh */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.h , Rs32.h ) :sat :<<16" , "1101 0101  010sssss  PP-ttttt 111ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_h16_sat_hh */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.h , Rs32.l ) :<<16"   , "1101 0101  010sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_addh_h16_hl */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.h , Rs32.l ) :sat :<<16" , "1101 0101  010sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_h16_sat_hl */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.h ) :<<16"   , "1101 0101  010sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_addh_h16_lh */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.h ) :sat :<<16" , "1101 0101  010sssss  PP-ttttt 101ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_h16_sat_lh */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.h ) :sat"    , "1101 0101  000sssss  PP-ttttt 11-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_l16_sat_hl */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.h )"         , "1101 0101  000sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* A2_addh_l16_hl */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.l ) :<<16"   , "1101 0101  010sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_addh_h16_ll */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.l ) :sat :<<16" , "1101 0101  010sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_h16_sat_ll */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.l ) :sat"    , "1101 0101  000sssss  PP-ttttt 10-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addh_l16_sat_ll */
HEXAGON_OPCODE ("Rd32 = add ( Rt32.l , Rs32.l )"         , "1101 0101  000sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* A2_addh_l16_ll */
HEXAGON_OPCODE ("Rd32 = add ( Ru32 , mpyi ( #u6:2 , Rs32 ) )" , "1101 1111   0ii sssss PPiddddd iiiuuuuu"    , 0xc, 0, 0) /* M4_mpyri_addr_u2 */
HEXAGON_OPCODE ("Rd32 = add ( Ru32 , mpyi ( Rs32 , #u6 ) )" , "1101 1111   1ii sssss PPiddddd iiiuuuuu"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M4_mpyri_addr */
HEXAGON_OPCODE ("Rd32 = add ( clb ( Rs32 ) , #s6 )"      , "1000 1100   001sssss PPiiiiii 000ddddd"     , 0xc, 0, 0) /* S4_clbaddi */
HEXAGON_OPCODE ("Rd32 = add ( clb ( Rss32 ) , #s6 )"     , "1000 1000 011sssss PPiiiiii 010ddddd"       , 0xc, 0, 0) /* S4_clbpaddi */
HEXAGON_OPCODE ("Rd32 = add ( pc , #u6 )"                , "0110 1010  01001001  PP-iiiii  i--ddddd"    , 0x8, 0, 0|A_EXTENDABLE_LOWERCASE) /* C4_addipc */
HEXAGON_OPCODE ("Rd32 = addasl ( Rt32 , Rs32 , #u3 )"    , "1100 0100   000 sssss PP0ttttt iiiddddd"    , 0xc, 0, 0) /* S2_addasl_rrri */
HEXAGON_OPCODE ("Rd32 = and ( Rs32 , #s10 )"             , "0111 0110  00isssss  PPiiiiii iiiddddd"     , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_andir */
HEXAGON_OPCODE ("Rd32 = and ( Rs32 , Rt32 )"             , "1111 0001  000sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_and */
HEXAGON_OPCODE ("Rd32 = and ( Rt32 , ~ Rs32 )"           , "1111 0001  100sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A4_andn */
HEXAGON_OPCODE ("Rd32 = asl ( Rs32 , #u5 ) :sat"         , "1000 1100 010sssss PP0iiiii 010ddddd"       , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_asl_i_r_sat */
HEXAGON_OPCODE ("Rd32 = asl ( Rs32 , #u5 )"              , "1000 1100 000sssss PP0iiiii 0  10ddddd"     , 0xc, 0, 0) /* S2_asl_i_r */
HEXAGON_OPCODE ("Rd32 = asl ( Rs32 , Rt32 ) :sat"        , "1100 0110  00-sssss  PP-ttttt 10-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_asl_r_r_sat */
HEXAGON_OPCODE ("Rd32 = asl ( Rs32 , Rt32 )"             , "1100 0110  01-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_asl_r_r */
HEXAGON_OPCODE ("Rd32 = aslh ( Rs32 )"                   , "0111 0000  000sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_aslh */
HEXAGON_OPCODE ("Rd32 = asr ( Rs32 , #u5 ) :rnd"         , "1000 1100 010sssss PP0iiiii 000ddddd"       , 0xc, 0, 0) /* S2_asr_i_r_rnd */
HEXAGON_OPCODE ("Rd32 = asr ( Rs32 , #u5 )"              , "1000 1100 000sssss PP0iiiii 0  00ddddd"     , 0xc, 0, 0) /* S2_asr_i_r */
HEXAGON_OPCODE ("Rd32 = asr ( Rs32 , Rt32 ) :sat"        , "1100 0110  00-sssss  PP-ttttt 00-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_asr_r_r_sat */
HEXAGON_OPCODE ("Rd32 = asr ( Rs32 , Rt32 )"             , "1100 0110  01-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_asr_r_r */
HEXAGON_OPCODE ("Rd32 = asrh ( Rs32 )"                   , "0111 0000  001sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_asrh */
HEXAGON_MAPPING ("Rd32 = asrrnd ( Rs32 , #u5 )"           , "0000dddddsssssiiiii0000000000000"           , HEXAGON_MAP_FNAME(S2_asr_i_r_rnd_goodsyntax)) /* mapped to Rd32=Rs32 or Rd32=asr(Rs32,#u5-1):rnd */
HEXAGON_OPCODE ("Rd32 = brev ( Rs32 )"                   , "1000 1100  010sssss  PP------ 1 10ddddd"    , 0xc, 0, 0) /* S2_brev */
HEXAGON_OPCODE ("Rd32 = cl0 ( Rs32 )"                    , "1000 1100  000sssss  PP------ 1 01ddddd"    , 0xc, 0, 0) /* S2_cl0 */
HEXAGON_OPCODE ("Rd32 = cl0 ( Rss32 )"                   , "1000 1000  010sssss  PP------ 010ddddd"     , 0xc, 0, 0) /* S2_cl0p */
HEXAGON_OPCODE ("Rd32 = cl1 ( Rs32 )"                    , "1000 1100  000sssss  PP------ 1 10ddddd"    , 0xc, 0, 0) /* S2_cl1 */
HEXAGON_OPCODE ("Rd32 = cl1 ( Rss32 )"                   , "1000 1000  010sssss  PP------ 100ddddd"     , 0xc, 0, 0) /* S2_cl1p */
HEXAGON_OPCODE ("Rd32 = clb ( Rs32 )"                    , "1000 1100  000sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* S2_clb */
HEXAGON_OPCODE ("Rd32 = clb ( Rss32 )"                   , "1000 1000  010sssss  PP------ 000ddddd"     , 0xc, 0, 0) /* S2_clbp */
HEXAGON_OPCODE ("Rd32 = clrbit ( Rs32 , #u5 )"           , "1000 1100   110sssss PP0iiiii 001ddddd"     , 0xc, 0, 0) /* S2_clrbit_i */
HEXAGON_OPCODE ("Rd32 = clrbit ( Rs32 , Rt32 )"          , "1100 0110  10-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_clrbit_r */
HEXAGON_OPCODE ("Rd32 = cmp.eq ( Rs32 , #s8 )"           , "0111 0011 -10sssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_rcmpeqi */
HEXAGON_OPCODE ("Rd32 = cmp.eq ( Rs32 , Rt32 )"          , "1111 0011  010sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A4_rcmpeq */
HEXAGON_OPCODE ("Rd32 = cmpy ( Rs32 , Rt32 ) :<<1 :rnd :sat" , "11101101101sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpyrs_s1 */
HEXAGON_OPCODE ("Rd32 = cmpy ( Rs32 , Rt32 ) :rnd :sat"  , "11101101001sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpyrs_s0 */
HEXAGON_OPCODE ("Rd32 = cmpy ( Rs32 , Rt32 * ) :<<1 :rnd :sat" , "11101101111sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpyrsc_s1 */
HEXAGON_OPCODE ("Rd32 = cmpy ( Rs32 , Rt32 * ) :rnd :sat" , "11101101011sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpyrsc_s0 */
HEXAGON_OPCODE ("Rd32 = cmpyiwh ( Rss32 , Rt32 ) :<<1 :rnd :sat" , "1100 0101  ---sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_cmpyi_wh */
HEXAGON_OPCODE ("Rd32 = cmpyiwh ( Rss32 , Rt32 * ) :<<1 :rnd :sat" , "1100 0101  ---sssss  PP-ttttt 101ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_cmpyi_whc */
HEXAGON_OPCODE ("Rd32 = cmpyrwh ( Rss32 , Rt32 ) :<<1 :rnd :sat" , "1100 0101  ---sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_cmpyr_wh */
HEXAGON_OPCODE ("Rd32 = cmpyrwh ( Rss32 , Rt32 * ) :<<1 :rnd :sat" , "1100 0101  ---sssss  PP-ttttt 111ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_cmpyr_whc */
HEXAGON_OPCODE ("Rd32 = combine ( Rt32.h , Rs32.h )"     , "1111 0011  100sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_combine_hh */
HEXAGON_OPCODE ("Rd32 = combine ( Rt32.h , Rs32.l )"     , "1111 0011  101sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_combine_hl */
HEXAGON_OPCODE ("Rd32 = combine ( Rt32.l , Rs32.h )"     , "1111 0011  110sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_combine_lh */
HEXAGON_OPCODE ("Rd32 = combine ( Rt32.l , Rs32.l )"     , "1111 0011  111sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_combine_ll */
HEXAGON_OPCODE ("Rd32 = convert_d2sf ( Rss32 )"          , "1000 1000  010sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_d2sf */
HEXAGON_OPCODE ("Rd32 = convert_df2sf ( Rss32 )"         , "1000 1000  000sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2sf */
HEXAGON_OPCODE ("Rd32 = convert_df2uw ( Rss32 ) :chop"   , "1000 1000  101sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2uw_chop */
HEXAGON_OPCODE ("Rd32 = convert_df2uw ( Rss32 )"         , "1000 1000  011sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2uw */
HEXAGON_OPCODE ("Rd32 = convert_df2w ( Rss32 ) :chop"    , "1000 1000  111sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2w_chop */
HEXAGON_OPCODE ("Rd32 = convert_df2w ( Rss32 )"          , "1000 1000  100sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2w */
HEXAGON_OPCODE ("Rd32 = convert_sf2uw ( Rs32 ) :chop"    , "1000 1011  011sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2uw_chop */
HEXAGON_OPCODE ("Rd32 = convert_sf2uw ( Rs32 )"          , "1000 1011  011sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2uw */
HEXAGON_OPCODE ("Rd32 = convert_sf2w ( Rs32 ) :chop"     , "1000 1011  100sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2w_chop */
HEXAGON_OPCODE ("Rd32 = convert_sf2w ( Rs32 )"           , "1000 1011  100sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2w */
HEXAGON_OPCODE ("Rd32 = convert_ud2sf ( Rss32 )"         , "1000 1000  001sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_ud2sf */
HEXAGON_OPCODE ("Rd32 = convert_uw2sf ( Rs32 )"          , "1000 1011  001sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_uw2sf */
HEXAGON_OPCODE ("Rd32 = convert_w2sf ( Rs32 )"           , "1000 1011  010sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_w2sf */
HEXAGON_OPCODE ("Rd32 = cround ( Rs32 , #u5 )"           , "1000 1100 111sssss PP0iiiii 00-ddddd"       , 0xc, 0, 0) /* A4_cround_ri */
HEXAGON_OPCODE ("Rd32 = cround ( Rs32 , Rt32 )"          , "1100 0110  11-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* A4_cround_rr */
HEXAGON_OPCODE ("Rd32 = ct0 ( Rs32 )"                    , "1000 1100  010sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* S2_ct0 */
HEXAGON_OPCODE ("Rd32 = ct0 ( Rss32 )"                   , "1000 1000  111sssss  PP------ 010ddddd"     , 0xc, 0, 0) /* S2_ct0p */
HEXAGON_OPCODE ("Rd32 = ct1 ( Rs32 )"                    , "1000 1100  010sssss  PP------ 1 01ddddd"    , 0xc, 0, 0) /* S2_ct1 */
HEXAGON_OPCODE ("Rd32 = ct1 ( Rss32 )"                   , "1000 1000  111sssss  PP------ 100ddddd"     , 0xc, 0, 0) /* S2_ct1p */
HEXAGON_OPCODE ("Rd32 = ctlbw ( Rss32 , Rt32 )"          , "0110 1100 110sssss PP0ttttt ---ddddd"       , 0x8, 0, 0|A_SOLO) /* Y5_ctlbw */
HEXAGON_OPCODE ("Rd32 = dctagr ( Rs32 )"                 , "1010 010 00 01sssss PP------ ---ddddd"      , 0x1, 0, 0|A_RESTRICT_AX) /* Y2_dctagr */
HEXAGON_OPCODE ("Rd32 = extract ( Rs32 , #u5 , #U5 )"    , "1000 1101 1IIsssss PP0iiiii IIIddddd"       , 0xc, 0, 0) /* S4_extract */
HEXAGON_OPCODE ("Rd32 = extract ( Rs32 , Rtt32 )"        , "1100 1001  00-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S4_extract_rp */
HEXAGON_OPCODE ("Rd32 = extractu ( Rs32 , #u5 , #U5 )"   , "1000 1101 0IIsssss PP0iiiii IIIddddd"       , 0xc, 0, 0) /* S2_extractu */
HEXAGON_OPCODE ("Rd32 = extractu ( Rs32 , Rtt32 )"       , "1100 1001  00-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_extractu_rp */
HEXAGON_OPCODE ("Rd32 = getimask ( Rs32 )"               , "0110 0110 000sssss PP------ ---ddddd"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_getimask */
HEXAGON_OPCODE ("Rd32 = iassignr ( Rs32 )"               , "0110 0110 011sssss PP------ ---ddddd"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_iassignr */
HEXAGON_OPCODE ("Rd32 = icdatar ( Rs32 )"                , "0101 0101  101sssss  PP------  ---ddddd"    , 0x4, 0, 0|A_SOLO) /* Y2_icdatar */
HEXAGON_OPCODE ("Rd32 = ictagr ( Rs32 )"                 , "0101 0101  111sssss  PP------  ---ddddd"    , 0x4, 0, 0|A_SOLO) /* Y2_ictagr */
HEXAGON_OPCODE ("Rd32 = l2tagr ( Rs32 )"                 , "1010 010 00 11sssss PP------ ---ddddd"      , 0x1, 0, 0|A_RESTRICT_AX) /* Y4_l2tagr */
HEXAGON_OPCODE ("Rd32 = lsl ( #s6 , Rt32 )"              , "1100 0110  10-iiiii  PP-ttttt 11iddddd"     , 0xc, 0, 0) /* S4_lsli */
HEXAGON_OPCODE ("Rd32 = lsl ( Rs32 , Rt32 )"             , "1100 0110  01-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_lsl_r_r */
HEXAGON_OPCODE ("Rd32 = lsr ( Rs32 , #u5 )"              , "1000 1100 000sssss PP0iiiii 0  01ddddd"     , 0xc, 0, 0) /* S2_lsr_i_r */
HEXAGON_OPCODE ("Rd32 = lsr ( Rs32 , Rt32 )"             , "1100 0110  01-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_lsr_r_r */
HEXAGON_OPCODE ("Rd32 = max ( Rs32 , Rt32 )"             , "1101 0101  110sssss  PP-ttttt 0--ddddd"     , 0xc, 0, 0) /* A2_max */
HEXAGON_OPCODE ("Rd32 = maxu ( Rs32 , Rt32 )"            , "1101 0101  110sssss  PP-ttttt 1--ddddd"     , 0xc, 0, 0) /* A2_maxu */
HEXAGON_OPCODE ("Rd32 = memb ( #g16:0 )"                 , "0100 1ii1 000  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrbgp */
HEXAGON_OPCODE ("Rd32 = memb ( gp + #u16:0 )"            , "0100 1ii1 000  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrbgp */
HEXAGON_OPCODE ("Rd32 = memb ( Rf32 = #U6 )"             , "1001 1 01 1 000  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrb_ap */
HEXAGON_MAPPING ("Rd32 = memb ( Rs32 )"                   , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadrb_zomap)) /* mapped to Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memb ( Rs32 + #s11:0 )"          , "1001 0 ii 1 000  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrb_io */
HEXAGON_OPCODE ("Rd32 = memb ( Rs32 + Rt32 << #0 )"      , "0011 1010 000  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrb_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memb ( Rs32 + Rt32 << #1 )"      , "0011 1010 000  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrb_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memb ( Rs32 + Rt32 << #2 )"      , "0011 1010 000  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrb_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memb ( Rs32 + Rt32 << #3 )"      , "0011 1010 000  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrb_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memb ( Rt32 << #0 + #U6 )"       , "1001 1 10 1 000  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrb_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memb ( Rt32 << #1 + #U6 )"       , "1001 1 10 1 000  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrb_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memb ( Rt32 << #2 + #U6 )"       , "1001 1 10 1 000  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrb_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memb ( Rt32 << #3 + #U6 )"       , "1001 1 10 1 000  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrb_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memb ( Rz32 ++ #s4:0 )"          , "1001 1 01 1 000  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrb_pi */
HEXAGON_OPCODE ("Rd32 = memb ( Rz32 ++ #s4:0 :circ ( Mu2 ) )" , "1001 1 00 1 000  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrb_pci */
HEXAGON_OPCODE ("Rd32 = memb ( Rz32 ++ Mu2 )"            , "1001 1 10 1 000  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrb_pr */
HEXAGON_OPCODE ("Rd32 = memb ( Rz32 ++ Mu2 :brev )"      , "1001 1 11 1 000  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrb_pbr */
HEXAGON_OPCODE ("Rd32 = memb ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 000  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrb_pcr */
HEXAGON_OPCODE ("Rd32 = membh ( Rf32 = #U6 )"            , "1001 1 01 0 001  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw2_ap */
HEXAGON_MAPPING ("Rd32 = membh ( Rs32 )"                  , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadbsw2_zomap)) /* mapped to Rd32=membh(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = membh ( Rs32 + #s11:1 )"         , "1001 0 ii 0 001  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadbsw2_io */
HEXAGON_OPCODE ("Rd32 = membh ( Rt32 << #0 + #U6 )"      , "1001 1 10 0 001  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw2_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = membh ( Rt32 << #1 + #U6 )"      , "1001 1 10 0 001  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw2_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = membh ( Rt32 << #2 + #U6 )"      , "1001 1 10 0 001  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw2_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = membh ( Rt32 << #3 + #U6 )"      , "1001 1 10 0 001  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw2_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = membh ( Rz32 ++ #s4:1 )"         , "1001 1 01 0 001  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw2_pi */
HEXAGON_OPCODE ("Rd32 = membh ( Rz32 ++ #s4:1 :circ ( Mu2 ) )" , "1001 1 00 0 001  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw2_pci */
HEXAGON_OPCODE ("Rd32 = membh ( Rz32 ++ Mu2 )"           , "1001 1 10 0 001  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw2_pr */
HEXAGON_OPCODE ("Rd32 = membh ( Rz32 ++ Mu2 :brev )"     , "1001 1 11 0 001  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw2_pbr */
HEXAGON_OPCODE ("Rd32 = membh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 001  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw2_pcr */
HEXAGON_OPCODE ("Rd32 = memh ( #g16:1 )"                 , "0100 1ii1 010  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrhgp */
HEXAGON_OPCODE ("Rd32 = memh ( gp + #u16:1 )"            , "0100 1ii1 010  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrhgp */
HEXAGON_OPCODE ("Rd32 = memh ( Rf32 = #U6 )"             , "1001 1 01 1 010  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrh_ap */
HEXAGON_MAPPING ("Rd32 = memh ( Rs32 )"                   , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadrh_zomap)) /* mapped to Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memh ( Rs32 + #s11:1 )"          , "1001 0 ii 1 010  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrh_io */
HEXAGON_OPCODE ("Rd32 = memh ( Rs32 + Rt32 << #0 )"      , "0011 1010 010  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrh_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memh ( Rs32 + Rt32 << #1 )"      , "0011 1010 010  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrh_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memh ( Rs32 + Rt32 << #2 )"      , "0011 1010 010  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrh_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memh ( Rs32 + Rt32 << #3 )"      , "0011 1010 010  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrh_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memh ( Rt32 << #0 + #U6 )"       , "1001 1 10 1 010  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrh_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memh ( Rt32 << #1 + #U6 )"       , "1001 1 10 1 010  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrh_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memh ( Rt32 << #2 + #U6 )"       , "1001 1 10 1 010  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrh_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memh ( Rt32 << #3 + #U6 )"       , "1001 1 10 1 010  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrh_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memh ( Rz32 ++ #s4:1 )"          , "1001 1 01 1 010  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrh_pi */
HEXAGON_OPCODE ("Rd32 = memh ( Rz32 ++ #s4:1 :circ ( Mu2 ) )" , "1001 1 00 1 010  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrh_pci */
HEXAGON_OPCODE ("Rd32 = memh ( Rz32 ++ Mu2 )"            , "1001 1 10 1 010  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrh_pr */
HEXAGON_OPCODE ("Rd32 = memh ( Rz32 ++ Mu2 :brev )"      , "1001 1 11 1 010  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrh_pbr */
HEXAGON_OPCODE ("Rd32 = memh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 010  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrh_pcr */
HEXAGON_OPCODE ("Rd32 = memub ( #g16:0 )"                , "0100 1ii1 001  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrubgp */
HEXAGON_OPCODE ("Rd32 = memub ( gp + #u16:0 )"           , "0100 1ii1 001  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrubgp */
HEXAGON_OPCODE ("Rd32 = memub ( Rf32 = #U6 )"            , "1001 1 01 1 001  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrub_ap */
HEXAGON_MAPPING ("Rd32 = memub ( Rs32 )"                  , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadrub_zomap)) /* mapped to Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memub ( Rs32 + #s11:0 )"         , "1001 0 ii 1 001  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrub_io */
HEXAGON_OPCODE ("Rd32 = memub ( Rs32 + Rt32 << #0 )"     , "0011 1010 001  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrub_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memub ( Rs32 + Rt32 << #1 )"     , "0011 1010 001  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrub_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memub ( Rs32 + Rt32 << #2 )"     , "0011 1010 001  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrub_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memub ( Rs32 + Rt32 << #3 )"     , "0011 1010 001  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrub_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memub ( Rt32 << #0 + #U6 )"      , "1001 1 10 1 001  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrub_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memub ( Rt32 << #1 + #U6 )"      , "1001 1 10 1 001  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrub_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memub ( Rt32 << #2 + #U6 )"      , "1001 1 10 1 001  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrub_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memub ( Rt32 << #3 + #U6 )"      , "1001 1 10 1 001  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrub_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memub ( Rz32 ++ #s4:0 )"         , "1001 1 01 1 001  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrub_pi */
HEXAGON_OPCODE ("Rd32 = memub ( Rz32 ++ #s4:0 :circ ( Mu2 ) )" , "1001 1 00 1 001  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrub_pci */
HEXAGON_OPCODE ("Rd32 = memub ( Rz32 ++ Mu2 )"           , "1001 1 10 1 001  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrub_pr */
HEXAGON_OPCODE ("Rd32 = memub ( Rz32 ++ Mu2 :brev )"     , "1001 1 11 1 001  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrub_pbr */
HEXAGON_OPCODE ("Rd32 = memub ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 001  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrub_pcr */
HEXAGON_OPCODE ("Rd32 = memubh ( Rf32 = #U6 )"           , "1001 1 01 0 011  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw2_ap */
HEXAGON_MAPPING ("Rd32 = memubh ( Rs32 )"                 , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadbzw2_zomap)) /* mapped to Rd32=memubh(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memubh ( Rs32 + #s11:1 )"        , "1001 0 ii 0 011  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadbzw2_io */
HEXAGON_OPCODE ("Rd32 = memubh ( Rt32 << #0 + #U6 )"     , "1001 1 10 0 011  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw2_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memubh ( Rt32 << #1 + #U6 )"     , "1001 1 10 0 011  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw2_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memubh ( Rt32 << #2 + #U6 )"     , "1001 1 10 0 011  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw2_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memubh ( Rt32 << #3 + #U6 )"     , "1001 1 10 0 011  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw2_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memubh ( Rz32 ++ #s4:1 )"        , "1001 1 01 0 011  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw2_pi */
HEXAGON_OPCODE ("Rd32 = memubh ( Rz32 ++ #s4:1 :circ ( Mu2 ) )" , "1001 1 00 0 011  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw2_pci */
HEXAGON_OPCODE ("Rd32 = memubh ( Rz32 ++ Mu2 )"          , "1001 1 10 0 011  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw2_pr */
HEXAGON_OPCODE ("Rd32 = memubh ( Rz32 ++ Mu2 :brev )"    , "1001 1 11 0 011  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw2_pbr */
HEXAGON_OPCODE ("Rd32 = memubh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 011  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw2_pcr */
HEXAGON_OPCODE ("Rd32 = memuh ( #g16:1 )"                , "0100 1ii1 011  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadruhgp */
HEXAGON_OPCODE ("Rd32 = memuh ( gp + #u16:1 )"           , "0100 1ii1 011  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadruhgp */
HEXAGON_OPCODE ("Rd32 = memuh ( Rf32 = #U6 )"            , "1001 1 01 1 011  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadruh_ap */
HEXAGON_MAPPING ("Rd32 = memuh ( Rs32 )"                  , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadruh_zomap)) /* mapped to Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memuh ( Rs32 + #s11:1 )"         , "1001 0 ii 1 011  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadruh_io */
HEXAGON_OPCODE ("Rd32 = memuh ( Rs32 + Rt32 << #0 )"     , "0011 1010 011  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadruh_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rs32 + Rt32 << #1 )"     , "0011 1010 011  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadruh_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rs32 + Rt32 << #2 )"     , "0011 1010 011  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadruh_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rs32 + Rt32 << #3 )"     , "0011 1010 011  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadruh_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rt32 << #0 + #U6 )"      , "1001 1 10 1 011  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadruh_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rt32 << #1 + #U6 )"      , "1001 1 10 1 011  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadruh_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rt32 << #2 + #U6 )"      , "1001 1 10 1 011  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadruh_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rt32 << #3 + #U6 )"      , "1001 1 10 1 011  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadruh_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memuh ( Rz32 ++ #s4:1 )"         , "1001 1 01 1 011  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadruh_pi */
HEXAGON_OPCODE ("Rd32 = memuh ( Rz32 ++ #s4:1 :circ ( Mu2 ) )" , "1001 1 00 1 011  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadruh_pci */
HEXAGON_OPCODE ("Rd32 = memuh ( Rz32 ++ Mu2 )"           , "1001 1 10 1 011  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadruh_pr */
HEXAGON_OPCODE ("Rd32 = memuh ( Rz32 ++ Mu2 :brev )"     , "1001 1 11 1 011  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadruh_pbr */
HEXAGON_OPCODE ("Rd32 = memuh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 011  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadruh_pcr */
HEXAGON_OPCODE ("Rd32 = memw ( #g16:2 )"                 , "0100 1ii1 100  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrigp */
HEXAGON_OPCODE ("Rd32 = memw ( gp + #u16:2 )"            , "0100 1ii1 100  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrigp */
HEXAGON_OPCODE ("Rd32 = memw ( Rf32 = #U6 )"             , "1001 1 01 1 100  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadri_ap */
HEXAGON_MAPPING ("Rd32 = memw ( Rs32 )"                   , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadri_zomap)) /* mapped to Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("Rd32 = memw ( Rs32 + #s11:2 )"          , "1001 0 ii 1 100  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadri_io */
HEXAGON_OPCODE ("Rd32 = memw ( Rs32 + Rt32 << #0 )"      , "0011 1010 100  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadri_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memw ( Rs32 + Rt32 << #1 )"      , "0011 1010 100  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadri_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memw ( Rs32 + Rt32 << #2 )"      , "0011 1010 100  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadri_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memw ( Rs32 + Rt32 << #3 )"      , "0011 1010 100  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadri_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memw ( Rt32 << #0 + #U6 )"       , "1001 1 10 1 100  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadri_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rd32 = memw ( Rt32 << #1 + #U6 )"       , "1001 1 10 1 100  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadri_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rd32 = memw ( Rt32 << #2 + #U6 )"       , "1001 1 10 1 100  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadri_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rd32 = memw ( Rt32 << #3 + #U6 )"       , "1001 1 10 1 100  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadri_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rd32 = memw ( Rz32 ++ #s4:2 )"          , "1001 1 01 1 100  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadri_pi */
HEXAGON_OPCODE ("Rd32 = memw ( Rz32 ++ #s4:2 :circ ( Mu2 ) )" , "1001 1 00 1 100  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadri_pci */
HEXAGON_OPCODE ("Rd32 = memw ( Rz32 ++ Mu2 )"            , "1001 1 10 1 100  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadri_pr */
HEXAGON_OPCODE ("Rd32 = memw ( Rz32 ++ Mu2 :brev )"      , "1001 1 11 1 100  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadri_pbr */
HEXAGON_OPCODE ("Rd32 = memw ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 100  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadri_pcr */
HEXAGON_OPCODE ("Rd32 = memw_locked ( Rs32 )"            , "1001 001 0 000 sssss PP00---- ---ddddd"     , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* L2_loadw_locked */
HEXAGON_OPCODE ("Rd32 = memw_phys ( Rs32 , Rt32 )"       , "1001 001 0 000 sssss PP1ttttt ---ddddd"     , 0x1, 0, 0|A_SOLO|A_MEMORY) /* L4_loadw_phys */
HEXAGON_OPCODE ("Rd32 = min ( Rt32 , Rs32 )"             , "1101 0101  101sssss  PP-ttttt 0--ddddd"     , 0xc, 0, 0) /* A2_min */
HEXAGON_OPCODE ("Rd32 = minu ( Rt32 , Rs32 )"            , "1101 0101  101sssss  PP-ttttt 1--ddddd"     , 0xc, 0, 0) /* A2_minu */
HEXAGON_OPCODE ("Rd32 = modwrap ( Rs32 , Rt32 )"         , "1101 0011  111sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A4_modwrapu */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :<<1 :rnd :sat" , "11101100101sssss  PP-ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_hh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :<<1 :rnd" , "11101100101sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_hh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :<<1 :sat" , "11101100100sssss  PP-ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_hh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :<<1"    , "11101100100sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpy_hh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :rnd :sat" , "11101100001sssss  PP-ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_hh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :rnd"    , "11101100001sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_hh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h ) :sat"    , "11101100000sssss  PP-ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_hh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.h )"         , "11101100000sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpy_hh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :<<1 :rnd :sat" , "11101100101sssss  PP-ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_hl_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :<<1 :rnd" , "11101100101sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_hl_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :<<1 :sat" , "11101100100sssss  PP-ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_hl_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :<<1"    , "11101100100sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpy_hl_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :rnd :sat" , "11101100001sssss  PP-ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_hl_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :rnd"    , "11101100001sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_hl_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l ) :sat"    , "11101100000sssss  PP-ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_hl_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.h , Rt32.l )"         , "11101100000sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpy_hl_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :<<1 :rnd :sat" , "11101100101sssss  PP-ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_lh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :<<1 :rnd" , "11101100101sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_lh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :<<1 :sat" , "11101100100sssss  PP-ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_lh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :<<1"    , "11101100100sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpy_lh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :rnd :sat" , "11101100001sssss  PP-ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_lh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :rnd"    , "11101100001sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_lh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h ) :sat"    , "11101100000sssss  PP-ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_lh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.h )"         , "11101100000sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpy_lh_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :<<1 :rnd :sat" , "11101100101sssss  PP-ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_ll_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :<<1 :rnd" , "11101100101sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_ll_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :<<1 :sat" , "11101100100sssss  PP-ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_ll_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :<<1"    , "11101100100sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpy_ll_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :rnd :sat" , "11101100001sssss  PP-ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_rnd_ll_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :rnd"    , "11101100001sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpy_rnd_ll_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l ) :sat"    , "11101100000sssss  PP-ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_sat_ll_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32.l , Rt32.l )"         , "11101100000sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpy_ll_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32.h ) :<<1 :rnd :sat" , "11101101101sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_hmmpyh_rs1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32.h ) :<<1 :sat" , "11101101101sssss  PP0ttttt 000ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_hmmpyh_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32.l ) :<<1 :rnd :sat" , "11101101111sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_hmmpyl_rs1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32.l ) :<<1 :sat" , "11101101101sssss  PP0ttttt 001ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_hmmpyl_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32 ) :<<1 :sat"   , "11101101111sssss  PP0ttttt 000ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_up_s1_sat */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32 ) :<<1"        , "11101101101sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpy_up_s1 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32 ) :rnd"        , "11101101001sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_dpmpyss_rnd_s0 */
HEXAGON_OPCODE ("Rd32 = mpy ( Rs32 , Rt32 )"             , "11101101000sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpy_up */
HEXAGON_MAPPING ("Rd32 = mpyi ( Rs32 , #m9 )"             , "0000dddddsssssiiiiiiiii000000000"           , HEXAGON_MAP_FNAME(M2_mpysmi)) /* mapped to Rd32=-mpyi(Rs32,#m9*(-1)) or Rd32=+mpyi(Rs32,#m9) */
HEXAGON_OPCODE ("Rd32 = mpyi ( Rs32 , Rt32 )"            , "11101101000sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpyi */
HEXAGON_OPCODE ("Rd32 = mpysu ( Rs32 , Rt32 )"           , "11101101011sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpysu_up */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.h , Rt32.h ) :<<1"   , "11101100110sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpyu_hh_s1 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.h , Rt32.h )"        , "11101100010sssss  PP-ttttt 011ddddd"        , 0xc, 0, 0) /* M2_mpyu_hh_s0 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.h , Rt32.l ) :<<1"   , "11101100110sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpyu_hl_s1 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.h , Rt32.l )"        , "11101100010sssss  PP-ttttt 010ddddd"        , 0xc, 0, 0) /* M2_mpyu_hl_s0 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.l , Rt32.h ) :<<1"   , "11101100110sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpyu_lh_s1 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.l , Rt32.h )"        , "11101100010sssss  PP-ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpyu_lh_s0 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.l , Rt32.l ) :<<1"   , "11101100110sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpyu_ll_s1 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32.l , Rt32.l )"        , "11101100010sssss  PP-ttttt 000ddddd"        , 0xc, 0, 0) /* M2_mpyu_ll_s0 */
HEXAGON_OPCODE ("Rd32 = mpyu ( Rs32 , Rt32 )"            , "11101101010sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_mpyu_up */
HEXAGON_MAPPING ("Rd32 = mpyui ( Rs32 , Rt32 )"           , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(M2_mpyui)) /* mapped to Rd32=mpyi(Rs32,Rt32) */
HEXAGON_OPCODE ("Rd32 = mux ( Pu4 , #s8 , #S8 )"         , "0111 101u uIIIIIII PPIiiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_muxii */
HEXAGON_OPCODE ("Rd32 = mux ( Pu4 , #s8 , Rs32 )"        , "0111 0011 1uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_muxri */
HEXAGON_OPCODE ("Rd32 = mux ( Pu4 , Rs32 , #s8 )"        , "0111 0011 0uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* C2_muxir */
HEXAGON_OPCODE ("Rd32 = mux ( Pu4 , Rs32 , Rt32 )"       , "1111 0100  ---sssss  PP-ttttt -uuddddd"     , 0xf, 0, 0) /* C2_mux */
HEXAGON_OPCODE ("Rd32 = neg ( Rs32 ) :sat"               , "1000 1100  100sssss  PP------ 1 10ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_negsat */
HEXAGON_MAPPING ("Rd32 = neg ( Rs32 )"                    , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(A2_neg)) /* mapped to Rd32=sub(#0,Rs32) */
HEXAGON_OPCODE ("Rd32 = normamt ( Rs32 )"                , "1000 1100  000sssss  PP------ 1 11ddddd"    , 0xc, 0, 0) /* S2_clbnorm */
HEXAGON_OPCODE ("Rd32 = normamt ( Rss32 )"               , "1000 1000  011sssss  PP------ 000ddddd"     , 0xc, 0, 0) /* S4_clbpnorm */
HEXAGON_MAPPING ("Rd32 = not ( Rs32 )"                    , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(A2_not)) /* mapped to Rd32=sub(#-1,Rs32) */
HEXAGON_OPCODE ("Rd32 = or ( Rs32 , #s10 )"              , "0111 0110  10isssss  PPiiiiii iiiddddd"     , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_orir */
HEXAGON_OPCODE ("Rd32 = or ( Rs32 , Rt32 )"              , "1111 0001  001sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_or */
HEXAGON_OPCODE ("Rd32 = or ( Rt32 , ~ Rs32 )"            , "1111 0001  101sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A4_orn */
HEXAGON_OPCODE ("Rd32 = parity ( Rs32 , Rt32 )"          , "1101 0101  111sssss  PP-ttttt ---ddddd"     , 0xc, 0, 0) /* S4_parity */
HEXAGON_OPCODE ("Rd32 = parity ( Rss32 , Rtt32 )"        , "1101 0000  ---sssss  PP-ttttt ---ddddd"     , 0xc, 0, 0) /* S2_parityp */
HEXAGON_OPCODE ("Rd32 = popcount ( Rss32 )"              , "1000 1000  011sssss  PP------ 011ddddd"     , 0xc, 0, 0) /* S5_popcountp */
HEXAGON_OPCODE ("Rd32 = round ( Rs32 , #u5 ) :sat"       , "1000 1100 111sssss PP0iiiii 11-ddddd"       , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A4_round_ri_sat */
HEXAGON_OPCODE ("Rd32 = round ( Rs32 , #u5 )"            , "1000 1100 111sssss PP0iiiii 10-ddddd"       , 0xc, 0, 0) /* A4_round_ri */
HEXAGON_OPCODE ("Rd32 = round ( Rs32 , Rt32 ) :sat"      , "1100 0110  11-sssss  PP-ttttt 11-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A4_round_rr_sat */
HEXAGON_OPCODE ("Rd32 = round ( Rs32 , Rt32 )"           , "1100 0110  11-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* A4_round_rr */
HEXAGON_OPCODE ("Rd32 = round ( Rss32 ) :sat"            , "1000 1000  110sssss  PP------ 001ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_roundsat */
HEXAGON_OPCODE ("Rd32 = sat ( Rss32 )"                   , "1000 1000  110sssss  PP------ 000ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_sat */
HEXAGON_OPCODE ("Rd32 = satb ( Rs32 )"                   , "1000 1100  110sssss  PP------ 1 11ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_satb */
HEXAGON_OPCODE ("Rd32 = sath ( Rs32 )"                   , "1000 1100  110sssss  PP------ 1 00ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_sath */
HEXAGON_OPCODE ("Rd32 = satub ( Rs32 )"                  , "1000 1100  110sssss  PP------ 1 10ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_satub */
HEXAGON_OPCODE ("Rd32 = satuh ( Rs32 )"                  , "1000 1100  110sssss  PP------ 1 01ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_satuh */
HEXAGON_OPCODE ("Rd32 = setbit ( Rs32 , #u5 )"           , "1000 1100   110sssss PP0iiiii 000ddddd"     , 0xc, 0, 0) /* S2_setbit_i */
HEXAGON_OPCODE ("Rd32 = setbit ( Rs32 , Rt32 )"          , "1100 0110  10-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_setbit_r */
HEXAGON_OPCODE ("Rd32 = sfadd ( Rs32 , Rt32 )"           , "11101011000sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfadd */
HEXAGON_OPCODE ("Rd32 = sffixupd ( Rs32 , Rt32 )"        , "11101011110sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sffixupd */
HEXAGON_OPCODE ("Rd32 = sffixupn ( Rs32 , Rt32 )"        , "11101011110sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sffixupn */
HEXAGON_OPCODE ("Rd32 = sffixupr ( Rs32 )"               , "1000 1011  101sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_sffixupr */
HEXAGON_OPCODE ("Rd32 = sfmake ( #u10 ) :neg"            , "1101 0110   01i ----- PPiiiiii iiiddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_sfimm_n */
HEXAGON_OPCODE ("Rd32 = sfmake ( #u10 ) :pos"            , "1101 0110   00i ----- PPiiiiii iiiddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_sfimm_p */
HEXAGON_OPCODE ("Rd32 = sfmax ( Rs32 , Rt32 )"           , "11101011100sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfmax */
HEXAGON_OPCODE ("Rd32 = sfmin ( Rs32 , Rt32 )"           , "11101011100sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfmin */
HEXAGON_OPCODE ("Rd32 = sfmpy ( Rs32 , Rt32 )"           , "11101011010sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfmpy */
HEXAGON_OPCODE ("Rd32 = sfsub ( Rs32 , Rt32 )"           , "11101011000sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0|A_XFLOAT) /* F2_sfsub */
HEXAGON_OPCODE ("Rd32 = sub ( #s10 , Rs32 )"             , "0111 0110  01isssss  PPiiiiii iiiddddd"     , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_subri */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.h , Rs32.h ) :<<16"   , "1101 0101  011sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_subh_h16_hh */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.h , Rs32.h ) :sat :<<16" , "1101 0101  011sssss  PP-ttttt 111ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_h16_sat_hh */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.h , Rs32.l ) :<<16"   , "1101 0101  011sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_subh_h16_hl */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.h , Rs32.l ) :sat :<<16" , "1101 0101  011sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_h16_sat_hl */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.h ) :<<16"   , "1101 0101  011sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_subh_h16_lh */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.h ) :sat :<<16" , "1101 0101  011sssss  PP-ttttt 101ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_h16_sat_lh */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.h ) :sat"    , "1101 0101  001sssss  PP-ttttt 11-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_l16_sat_hl */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.h )"         , "1101 0101  001sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* A2_subh_l16_hl */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.l ) :<<16"   , "1101 0101  011sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_subh_h16_ll */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.l ) :sat :<<16" , "1101 0101  011sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_h16_sat_ll */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.l ) :sat"    , "1101 0101  001sssss  PP-ttttt 10-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_subh_l16_sat_ll */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32.l , Rs32.l )"         , "1101 0101  001sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* A2_subh_l16_ll */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32 , Rs32 ) :sat :deprecated" , "1101 0101  100sssss  PP-ttttt 1--ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* dep_A2_subsat */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32 , Rs32 ) :sat"        , "1111 0110  110sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_subsat */
HEXAGON_OPCODE ("Rd32 = sub ( Rt32 , Rs32 )"             , "1111 0011  001sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_sub */
HEXAGON_OPCODE ("Rd32 = swiz ( Rs32 )"                   , "1000 1100  100sssss  PP------ 1 11ddddd"    , 0xc, 0, 0) /* A2_swiz */
HEXAGON_OPCODE ("Rd32 = sxtb ( Rs32 )"                   , "0111 0000  101sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_sxtb */
HEXAGON_OPCODE ("Rd32 = sxth ( Rs32 )"                   , "0111 0000  111sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_sxth */
HEXAGON_OPCODE ("Rd32 = tlboc ( Rss32 )"                 , "0110 1100 111sssss PP------ ---ddddd"       , 0x8, 0, 0|A_SOLO) /* Y5_tlboc */
HEXAGON_OPCODE ("Rd32 = tlbp ( Rs32 )"                   , "0110 1100 100sssss PP------ ---ddddd"       , 0x8, 0, 0|A_SOLO) /* Y2_tlbp */
HEXAGON_OPCODE ("Rd32 = togglebit ( Rs32 , #u5 )"        , "1000 1100   110sssss PP0iiiii 010ddddd"     , 0xc, 0, 0) /* S2_togglebit_i */
HEXAGON_OPCODE ("Rd32 = togglebit ( Rs32 , Rt32 )"       , "1100 0110  10-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_togglebit_r */
HEXAGON_OPCODE ("Rd32 = vaddh ( Rs32 , Rt32 ) :sat"      , "1111 0110  001sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_svaddhs */
HEXAGON_OPCODE ("Rd32 = vaddh ( Rs32 , Rt32 )"           , "1111 0110  000sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_svaddh */
HEXAGON_OPCODE ("Rd32 = vaddhub ( Rss32 , Rtt32 ) :sat"  , "1100 0001  01-sssss  PP-ttttt 001ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A5_vaddhubs */
HEXAGON_OPCODE ("Rd32 = vadduh ( Rs32 , Rt32 ) :sat"     , "1111 0110  011sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_svadduhs */
HEXAGON_OPCODE ("Rd32 = vasrhub ( Rss32 , #u4 ) :raw"    , "1000 1000 011sssss PP00iiii 100ddddd"       , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S5_asrhub_rnd_sat */
HEXAGON_MAPPING ("Rd32 = vasrhub ( Rss32 , #u4 ) :rnd :sat" , "0000dddddsssssiiii00000000000000"           , HEXAGON_MAP_FNAME(S5_asrhub_rnd_sat_goodsyntax)) /* mapped to Rd32=vsathub(Rss32) or Rd32=vasrhub(Rss32,#u4-1):raw */
HEXAGON_OPCODE ("Rd32 = vasrhub ( Rss32 , #u4 ) :sat"    , "1000 1000 011sssss PP00iiii 101ddddd"       , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S5_asrhub_sat */
HEXAGON_OPCODE ("Rd32 = vasrw ( Rss32 , #u5 )"           , "1000 1000 110sssss PP0iiiii 010ddddd"       , 0xc, 0, 0) /* S2_asr_i_svw_trun */
HEXAGON_OPCODE ("Rd32 = vasrw ( Rss32 , Rt32 )"          , "1100 0101  ---sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_asr_r_svw_trun */
HEXAGON_OPCODE ("Rd32 = vavgh ( Rs32 , Rt32 ) :rnd"      , "1111 0111  -01sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_svavghs */
HEXAGON_OPCODE ("Rd32 = vavgh ( Rs32 , Rt32 )"           , "1111 0111  -00sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_svavgh */
HEXAGON_OPCODE ("Rd32 = vdmpy ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "111010011--sssss  PP0ttttt -00ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmpyrs_s1 */
HEXAGON_OPCODE ("Rd32 = vdmpy ( Rss32 , Rtt32 ) :rnd :sat" , "111010010--sssss  PP0ttttt -00ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmpyrs_s0 */
HEXAGON_OPCODE ("Rd32 = vitpack ( Ps4 , Pt4 )"           , "1000 1001   -00 ---ss  PP----tt --- ddddd"  , 0xc, 0, 0) /* C2_vitpack */
HEXAGON_OPCODE ("Rd32 = vmpyh ( Rs32 , Rt32 ) :<<1 :rnd :sat" , "11101101101sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2s_s1pack */
HEXAGON_OPCODE ("Rd32 = vmpyh ( Rs32 , Rt32 ) :rnd :sat" , "11101101001sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2s_s0pack */
HEXAGON_OPCODE ("Rd32 = vnavgh ( Rt32 , Rs32 )"          , "1111 0111  -11sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_svnavgh */
HEXAGON_OPCODE ("Rd32 = vraddh ( Rss32 , Rtt32 )"        , "111010010-1sssss  PP0ttttt 111ddddd"        , 0xc, 0, 0) /* M2_vraddh */
HEXAGON_OPCODE ("Rd32 = vradduh ( Rss32 , Rtt32 )"       , "111010010--sssss  PP0ttttt -01ddddd"        , 0xc, 0, 0) /* M2_vradduh */
HEXAGON_MAPPING ("Rd32 = vrcmpys ( Rss32 , Rt32 ) :<<1 :rnd :sat" , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(M2_vrcmpys_s1rp)) /* mapped to Rd32=vrcmpys(Rss32,Rtt32):<<1:rnd:sat:raw:hi or Rd32=vrcmpys(Rss32,Rtt32):<<1:rnd:sat:raw:lo */
HEXAGON_OPCODE ("Rd32 = vrcmpys ( Rss32 , Rtt32 ) :<<1 :rnd :sat :raw :hi" , "111010011-1sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_s1rp_h */
HEXAGON_OPCODE ("Rd32 = vrcmpys ( Rss32 , Rtt32 ) :<<1 :rnd :sat :raw :lo" , "111010011-1sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_s1rp_l */
HEXAGON_OPCODE ("Rd32 = vrndwh ( Rss32 ) :sat"           , "1000 1000  100sssss  PP------ 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vrndpackwhs */
HEXAGON_OPCODE ("Rd32 = vrndwh ( Rss32 )"                , "1000 1000  100sssss  PP------ 100ddddd"     , 0xc, 0, 0) /* S2_vrndpackwh */
HEXAGON_OPCODE ("Rd32 = vsathb ( Rs32 )"                 , "1000 1100  10-sssss  PP------ 00-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_svsathb */
HEXAGON_OPCODE ("Rd32 = vsathb ( Rss32 )"                , "1000 1000  000sssss  PP------ 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsathb */
HEXAGON_OPCODE ("Rd32 = vsathub ( Rs32 )"                , "1000 1100  10-sssss  PP------ 01-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_svsathub */
HEXAGON_OPCODE ("Rd32 = vsathub ( Rss32 )"               , "1000 1000  000sssss  PP------ 000ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsathub */
HEXAGON_OPCODE ("Rd32 = vsatwh ( Rss32 )"                , "1000 1000  000sssss  PP------ 010ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsatwh */
HEXAGON_OPCODE ("Rd32 = vsatwuh ( Rss32 )"               , "1000 1000  000sssss  PP------ 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsatwuh */
HEXAGON_OPCODE ("Rd32 = vsplatb ( Rs32 )"                , "1000 1100  010sssss  PP------ 1 11ddddd"    , 0xc, 0, 0) /* S2_vsplatrb */
HEXAGON_OPCODE ("Rd32 = vsubh ( Rt32 , Rs32 ) :sat"      , "1111 0110  101sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_svsubhs */
HEXAGON_OPCODE ("Rd32 = vsubh ( Rt32 , Rs32 )"           , "1111 0110  100sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_svsubh */
HEXAGON_OPCODE ("Rd32 = vsubuh ( Rt32 , Rs32 ) :sat"     , "1111 0110  111sssss  PP-ttttt ---ddddd"     , 0xf, 0|IMPLICIT_SR_OVF, 0) /* A2_svsubuhs */
HEXAGON_OPCODE ("Rd32 = vtrunehb ( Rss32 )"              , "1000 1000  100sssss  PP------ 010ddddd"     , 0xc, 0, 0) /* S2_vtrunehb */
HEXAGON_OPCODE ("Rd32 = vtrunohb ( Rss32 )"              , "1000 1000  100sssss  PP------ 000ddddd"     , 0xc, 0, 0) /* S2_vtrunohb */
HEXAGON_OPCODE ("Rd32 = xor ( Rs32 , Rt32 )"             , "1111 0001  011sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_xor */
HEXAGON_MAPPING ("Rd32 = zxtb ( Rs32 )"                   , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(A2_zxtb)) /* mapped to Rd32=and(Rs32,#255) */
HEXAGON_OPCODE ("Rd32 = zxth ( Rs32 )"                   , "0111 0000  110sssss  PP0----- ---ddddd"     , 0xf, 0, 0) /* A2_zxth */
HEXAGON_MAPPING ("Rdd32 = #s8"                            , "0000dddddiiiiiiii000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpi)) /* mapped to Rdd32=combine(#-1,#s8) or Rdd32=combine(#0,#s8) */
HEXAGON_OPCODE ("Rdd32 = Css32"                          , "0110 1000  000sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* A4_tfrcpp */
HEXAGON_OPCODE ("Rdd32 = Gss32"                          , "0110 1000  001sssss  PP------  ---ddddd"    , 0x8, 0, 0) /* G4_tfrgcpp */
HEXAGON_MAPPING ("Rdd32 = Rss32"                          , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrp)) /* mapped to Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("Rdd32 = Sss64"                          , "0110 1111 --ssssss PP------ ---ddddd"       , 0x8, 0, 0) /* Y4_tfrscpp */
HEXAGON_OPCODE ("Rdd32 = abs ( Rss32 )"                  , "1000 0000  100sssss  PP------ 1 10ddddd"    , 0xc, 0, 0) /* A2_absp */
HEXAGON_MAPPING ("Rdd32 = add ( Rs32 , Rtt32 )"           , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(A2_addsp)) /* mapped to Rdd32=add(Rss32,Rtt32):raw:hi or Rdd32=add(Rss32,Rtt32):raw:lo */
HEXAGON_OPCODE ("Rdd32 = add ( Rss32 , Rtt32 ) :raw :hi" , "1101 0011  011sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A2_addsph */
HEXAGON_OPCODE ("Rdd32 = add ( Rss32 , Rtt32 ) :raw :lo" , "1101 0011  011sssss  PP-ttttt 110ddddd"     , 0xc, 0, 0) /* A2_addspl */
HEXAGON_OPCODE ("Rdd32 = add ( Rss32 , Rtt32 ) :sat"     , "1101 0011  011sssss  PP-ttttt 101ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_addpsat */
HEXAGON_OPCODE ("Rdd32 = add ( Rss32 , Rtt32 )"          , "1101 0011  000sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A2_addp */
HEXAGON_OPCODE ("Rdd32 = add ( Rss32 , Rtt32 , Px4 ) :carry" , "1100 0010  110sssss  PP-ttttt -xxddddd"     , 0xc, 0, 0|A_LATEPRED) /* A4_addp_c */
HEXAGON_OPCODE ("Rdd32 = and ( Rss32 , Rtt32 )"          , "1101 0011  111sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_andp */
HEXAGON_OPCODE ("Rdd32 = and ( Rtt32 , ~ Rss32 )"        , "1101 0011  111sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A4_andnp */
HEXAGON_OPCODE ("Rdd32 = asl ( Rss32 , #u6 )"            , "1000 0000 000sssss PPiiiiii 010ddddd"       , 0xc, 0, 0) /* S2_asl_i_p */
HEXAGON_OPCODE ("Rdd32 = asl ( Rss32 , Rt32 )"           , "1100 0011  10-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_asl_r_p */
HEXAGON_OPCODE ("Rdd32 = asr ( Rss32 , #u6 ) :rnd"       , "1000 0000 110sssss PPiiiiii 1 11ddddd"      , 0xc, 0, 0) /* S2_asr_i_p_rnd */
HEXAGON_OPCODE ("Rdd32 = asr ( Rss32 , #u6 )"            , "1000 0000 000sssss PPiiiiii 000ddddd"       , 0xc, 0, 0) /* S2_asr_i_p */
HEXAGON_OPCODE ("Rdd32 = asr ( Rss32 , Rt32 )"           , "1100 0011  10-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_asr_r_p */
HEXAGON_MAPPING ("Rdd32 = asrrnd ( Rss32 , #u6 )"         , "0000dddddsssssiiiiii000000000000"           , HEXAGON_MAP_FNAME(S2_asr_i_p_rnd_goodsyntax)) /* mapped to Rdd32=Rss32 or Rdd32=asr(Rss32,#u5-1):rnd */
HEXAGON_OPCODE ("Rdd32 = bitsplit ( Rs32 , #u5 )"        , "1000 1000 110sssss PP0iiiii 100ddddd"       , 0xc, 0, 0) /* A4_bitspliti */
HEXAGON_OPCODE ("Rdd32 = bitsplit ( Rs32 , Rt32 )"       , "1101 0100  --1sssss  PP-ttttt ---ddddd"     , 0xc, 0, 0) /* A4_bitsplit */
HEXAGON_OPCODE ("Rdd32 = brev ( Rss32 )"                 , "1000 0000  110sssss  PP------ 1 10ddddd"    , 0xc, 0, 0) /* S2_brevp */
HEXAGON_OPCODE ("Rdd32 = cmpy ( Rs32 , Rt32 ) :<<1 :sat" , "11100101100sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpys_s1 */
HEXAGON_OPCODE ("Rdd32 = cmpy ( Rs32 , Rt32 ) :sat"      , "11100101000sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpys_s0 */
HEXAGON_OPCODE ("Rdd32 = cmpy ( Rs32 , Rt32 * ) :<<1 :sat" , "11100101110sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpysc_s1 */
HEXAGON_OPCODE ("Rdd32 = cmpy ( Rs32 , Rt32 * ) :sat"    , "11100101010sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmpysc_s0 */
HEXAGON_OPCODE ("Rdd32 = cmpyi ( Rs32 , Rt32 )"          , "11100101000sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_cmpyi_s0 */
HEXAGON_OPCODE ("Rdd32 = cmpyr ( Rs32 , Rt32 )"          , "11100101000sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* M2_cmpyr_s0 */
HEXAGON_OPCODE ("Rdd32 = combine ( #s8 , #S8 )"          , "0111 1100 0IIIIIII PPIiiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A2_combineii */
HEXAGON_OPCODE ("Rdd32 = combine ( #s8 , #U6 )"          , "0111 1100 1--IIIII PPIiiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_UPPERCASE) /* A4_combineii */
HEXAGON_OPCODE ("Rdd32 = combine ( #s8 , Rs32 )"         , "0111 0011 -01sssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_combineir */
HEXAGON_OPCODE ("Rdd32 = combine ( Rs32 , #s8 )"         , "0111 0011 -00sssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_EXTENDABLE_LOWERCASE) /* A4_combineri */
HEXAGON_OPCODE ("Rdd32 = combine ( Rs32 , Rt32 )"        , "1111 0101  0--sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* A2_combinew */
HEXAGON_OPCODE ("Rdd32 = convert_d2df ( Rss32 )"         , "1000 0000  111sssss  PP0----- 0 11ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_d2df */
HEXAGON_OPCODE ("Rdd32 = convert_df2d ( Rss32 ) :chop"   , "1000 0000  111sssss  PP0----- 1 10ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2d_chop */
HEXAGON_OPCODE ("Rdd32 = convert_df2d ( Rss32 )"         , "1000 0000  111sssss  PP0----- 0 00ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2d */
HEXAGON_OPCODE ("Rdd32 = convert_df2ud ( Rss32 ) :chop"  , "1000 0000  111sssss  PP0----- 1 11ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2ud_chop */
HEXAGON_OPCODE ("Rdd32 = convert_df2ud ( Rss32 )"        , "1000 0000  111sssss  PP0----- 0 01ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_df2ud */
HEXAGON_OPCODE ("Rdd32 = convert_sf2d ( Rs32 ) :chop"    , "1000 0100  1--sssss  PP------ 110ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2d_chop */
HEXAGON_OPCODE ("Rdd32 = convert_sf2d ( Rs32 )"          , "1000 0100  1--sssss  PP------ 100ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2d */
HEXAGON_OPCODE ("Rdd32 = convert_sf2df ( Rs32 )"         , "1000 0100  1--sssss  PP------ 000ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2df */
HEXAGON_OPCODE ("Rdd32 = convert_sf2ud ( Rs32 ) :chop"   , "1000 0100  1--sssss  PP------ 101ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2ud_chop */
HEXAGON_OPCODE ("Rdd32 = convert_sf2ud ( Rs32 )"         , "1000 0100  1--sssss  PP------ 011ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_sf2ud */
HEXAGON_OPCODE ("Rdd32 = convert_ud2df ( Rss32 )"        , "1000 0000  111sssss  PP0----- 0 10ddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_conv_ud2df */
HEXAGON_OPCODE ("Rdd32 = convert_uw2df ( Rs32 )"         , "1000 0100  1--sssss  PP------ 001ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_uw2df */
HEXAGON_OPCODE ("Rdd32 = convert_w2df ( Rs32 )"          , "1000 0100  1--sssss  PP------ 010ddddd"     , 0xc, 0, 0|A_XFLOAT) /* F2_conv_w2df */
HEXAGON_OPCODE ("Rdd32 = decbin ( Rss32 , Rtt32 )"       , "1100 0001  11-sssss  PP-ttttt 11-ddddd"     , 0xc, 0|IMPLICIT_P0, 0|A_LATEPRED) /* S2_cabacdecbin */
HEXAGON_OPCODE ("Rdd32 = deinterleave ( Rss32 )"         , "1000 0000  110sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* S2_deinterleave */
HEXAGON_OPCODE ("Rdd32 = dfmake ( #u10 ) :neg"           , "1101 1001   01i ----- PPiiiiii iiiddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_dfimm_n */
HEXAGON_OPCODE ("Rdd32 = dfmake ( #u10 ) :pos"           , "1101 1001   00i ----- PPiiiiii iiiddddd"    , 0xc, 0, 0|A_XFLOAT) /* F2_dfimm_p */
HEXAGON_OPCODE ("Rdd32 = extract ( Rss32 , #u6 , #U6 )"  , "1000 1010 IIIsssss PPiiiiii IIIddddd"       , 0xc, 0, 0) /* S4_extractp */
HEXAGON_OPCODE ("Rdd32 = extract ( Rss32 , Rtt32 )"      , "1100 0001  11-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S4_extractp_rp */
HEXAGON_OPCODE ("Rdd32 = extractu ( Rss32 , #u6 , #U6 )" , "1000 0001 IIIsssss PPiiiiii IIIddddd"       , 0xc, 0, 0) /* S2_extractup */
HEXAGON_OPCODE ("Rdd32 = extractu ( Rss32 , Rtt32 )"     , "1100 0001  00-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_extractup_rp */
HEXAGON_OPCODE ("Rdd32 = interleave ( Rss32 )"           , "1000 0000  110sssss  PP------ 1 01ddddd"    , 0xc, 0, 0) /* S2_interleave */
HEXAGON_OPCODE ("Rdd32 = lfs ( Rss32 , Rtt32 )"          , "1100 0001  10-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_lfsp */
HEXAGON_OPCODE ("Rdd32 = lsl ( Rss32 , Rt32 )"           , "1100 0011  10-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_lsl_r_p */
HEXAGON_OPCODE ("Rdd32 = lsr ( Rss32 , #u6 )"            , "1000 0000 000sssss PPiiiiii 001ddddd"       , 0xc, 0, 0) /* S2_lsr_i_p */
HEXAGON_OPCODE ("Rdd32 = lsr ( Rss32 , Rt32 )"           , "1100 0011  10-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_lsr_r_p */
HEXAGON_OPCODE ("Rdd32 = mask ( Pt4 )"                   , "1000    0110   --- -----  PP----tt --- ddddd", 0xc, 0, 0) /* C2_mask */
HEXAGON_OPCODE ("Rdd32 = max ( Rss32 , Rtt32 )"          , "1101 0011  110sssss  PP-ttttt 100ddddd"     , 0xc, 0, 0) /* A2_maxp */
HEXAGON_OPCODE ("Rdd32 = maxu ( Rss32 , Rtt32 )"         , "1101 0011  110sssss  PP-ttttt 101ddddd"     , 0xc, 0, 0) /* A2_maxup */
HEXAGON_OPCODE ("Rdd32 = membh ( Rf32 = #U6 )"           , "1001 1 01 0 111  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw4_ap */
HEXAGON_MAPPING ("Rdd32 = membh ( Rs32 )"                 , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadbsw4_zomap)) /* mapped to Rdd32=membh(Rs32+#0) */
HEXAGON_OPCODE ("Rdd32 = membh ( Rs32 + #s11:2 )"        , "1001 0 ii 0 111  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadbsw4_io */
HEXAGON_OPCODE ("Rdd32 = membh ( Rt32 << #0 + #U6 )"     , "1001 1 10 0 111  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw4_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rdd32 = membh ( Rt32 << #1 + #U6 )"     , "1001 1 10 0 111  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw4_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rdd32 = membh ( Rt32 << #2 + #U6 )"     , "1001 1 10 0 111  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw4_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rdd32 = membh ( Rt32 << #3 + #U6 )"     , "1001 1 10 0 111  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbsw4_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rdd32 = membh ( Rz32 ++ #s4:2 )"        , "1001 1 01 0 111  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw4_pi */
HEXAGON_OPCODE ("Rdd32 = membh ( Rz32 ++ #s4:2 :circ ( Mu2 ) )" , "1001 1 00 0 111  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw4_pci */
HEXAGON_OPCODE ("Rdd32 = membh ( Rz32 ++ Mu2 )"          , "1001 1 10 0 111  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw4_pr */
HEXAGON_OPCODE ("Rdd32 = membh ( Rz32 ++ Mu2 :brev )"    , "1001 1 11 0 111  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw4_pbr */
HEXAGON_OPCODE ("Rdd32 = membh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 111  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbsw4_pcr */
HEXAGON_OPCODE ("Rdd32 = memd ( #g16:3 )"                , "0100 1ii1 110  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrdgp */
HEXAGON_OPCODE ("Rdd32 = memd ( gp + #u16:3 )"           , "0100 1ii1 110  iiiii  PPiiiiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrdgp */
HEXAGON_OPCODE ("Rdd32 = memd ( Rf32 = #U6 )"            , "1001 1 01 1 110  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrd_ap */
HEXAGON_MAPPING ("Rdd32 = memd ( Rs32 )"                  , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadrd_zomap)) /* mapped to Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("Rdd32 = memd ( Rs32 + #s11:3 )"         , "1001 0 ii 1 110  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadrd_io */
HEXAGON_OPCODE ("Rdd32 = memd ( Rs32 + Rt32 << #0 )"     , "0011 1010 110  sssss  PP0ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrd_rr_expand_shamt_0 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rs32 + Rt32 << #1 )"     , "0011 1010 110  sssss  PP0ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrd_rr_expand_shamt_1 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rs32 + Rt32 << #2 )"     , "0011 1010 110  sssss  PP1ttttt  0--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrd_rr_expand_shamt_2 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rs32 + Rt32 << #3 )"     , "0011 1010 110  sssss  PP1ttttt  1--ddddd"   , 0x3, 0, 0|A_MEMORY) /* L4_loadrd_rr_expand_shamt_3 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rt32 << #0 + #U6 )"      , "1001 1 10 1 110  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrd_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rt32 << #1 + #U6 )"      , "1001 1 10 1 110  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrd_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rt32 << #2 + #U6 )"      , "1001 1 10 1 110  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrd_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rt32 << #3 + #U6 )"      , "1001 1 10 1 110  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadrd_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rdd32 = memd ( Rz32 ++ #s4:3 )"         , "1001 1 01 1 110  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrd_pi */
HEXAGON_OPCODE ("Rdd32 = memd ( Rz32 ++ #s4:3 :circ ( Mu2 ) )" , "1001 1 00 1 110  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrd_pci */
HEXAGON_OPCODE ("Rdd32 = memd ( Rz32 ++ Mu2 )"           , "1001 1 10 1 110  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrd_pr */
HEXAGON_OPCODE ("Rdd32 = memd ( Rz32 ++ Mu2 :brev )"     , "1001 1 11 1 110  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrd_pbr */
HEXAGON_OPCODE ("Rdd32 = memd ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 1 110  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadrd_pcr */
HEXAGON_OPCODE ("Rdd32 = memd_locked ( Rs32 )"           , "1001 001 0 000 sssss PP01---- ---ddddd"     , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* L4_loadd_locked */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rf32 = #U6 )"          , "1001 1 01 0 101  fffff  PP01IIII  -IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw4_ap */
HEXAGON_MAPPING ("Rdd32 = memubh ( Rs32 )"                , "0000dddddsssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadbzw4_zomap)) /* mapped to Rdd32=memubh(Rs32+#0) */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rs32 + #s11:2 )"       , "1001 0 ii 0 101  sssss  PPiiiiii  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadbzw4_io */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rt32 << #0 + #U6 )"    , "1001 1 10 0 101  ttttt  PP01IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw4_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rt32 << #1 + #U6 )"    , "1001 1 10 0 101  ttttt  PP01IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw4_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rt32 << #2 + #U6 )"    , "1001 1 10 0 101  ttttt  PP11IIII  0IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw4_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rt32 << #3 + #U6 )"    , "1001 1 10 0 101  ttttt  PP11IIII  1IIddddd" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadbzw4_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rz32 ++ #s4:2 )"       , "1001 1 01 0 101  zzzzz  PP00---i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw4_pi */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rz32 ++ #s4:2 :circ ( Mu2 ) )" , "1001 1 00 0 101  zzzzz  PPu0--0i  iiiddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw4_pci */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rz32 ++ Mu2 )"         , "1001 1 10 0 101  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw4_pr */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rz32 ++ Mu2 :brev )"   , "1001 1 11 0 101  zzzzz  PPu0----  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw4_pbr */
HEXAGON_OPCODE ("Rdd32 = memubh ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 101  zzzzz  PPu0--1-  0--ddddd" , 0x3, 0, 0|A_MEMORY) /* L2_loadbzw4_pcr */
HEXAGON_OPCODE ("Rdd32 = min ( Rtt32 , Rss32 )"          , "1101 0011  101sssss  PP-ttttt 110ddddd"     , 0xc, 0, 0) /* A2_minp */
HEXAGON_OPCODE ("Rdd32 = minu ( Rtt32 , Rss32 )"         , "1101 0011  101sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A2_minup */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.h ) :<<1 :rnd" , "11100100101sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_hh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.h ) :<<1"   , "11100100100sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyd_hh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.h ) :rnd"   , "11100100001sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_hh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.h )"        , "11100100000sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyd_hh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.l ) :<<1 :rnd" , "11100100101sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_hl_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.l ) :<<1"   , "11100100100sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyd_hl_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.l ) :rnd"   , "11100100001sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_hl_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.h , Rt32.l )"        , "11100100000sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyd_hl_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.h ) :<<1 :rnd" , "11100100101sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_lh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.h ) :<<1"   , "11100100100sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyd_lh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.h ) :rnd"   , "11100100001sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_lh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.h )"        , "11100100000sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyd_lh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.l ) :<<1 :rnd" , "11100100101sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_ll_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.l ) :<<1"   , "11100100100sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyd_ll_s1 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.l ) :rnd"   , "11100100001sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyd_rnd_ll_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32.l , Rt32.l )"        , "11100100000sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyd_ll_s0 */
HEXAGON_OPCODE ("Rdd32 = mpy ( Rs32 , Rt32 )"            , "11100101000sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_dpmpyss_s0 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.h , Rt32.h ) :<<1"  , "11100100110sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyud_hh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.h , Rt32.h )"       , "11100100010sssss  PP-ttttt -11ddddd"        , 0xc, 0, 0) /* M2_mpyud_hh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.h , Rt32.l ) :<<1"  , "11100100110sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyud_hl_s1 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.h , Rt32.l )"       , "11100100010sssss  PP-ttttt -10ddddd"        , 0xc, 0, 0) /* M2_mpyud_hl_s0 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.l , Rt32.h ) :<<1"  , "11100100110sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyud_lh_s1 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.l , Rt32.h )"       , "11100100010sssss  PP-ttttt -01ddddd"        , 0xc, 0, 0) /* M2_mpyud_lh_s0 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.l , Rt32.l ) :<<1"  , "11100100110sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyud_ll_s1 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32.l , Rt32.l )"       , "11100100010sssss  PP-ttttt -00ddddd"        , 0xc, 0, 0) /* M2_mpyud_ll_s0 */
HEXAGON_OPCODE ("Rdd32 = mpyu ( Rs32 , Rt32 )"           , "11100101010sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_dpmpyuu_s0 */
HEXAGON_OPCODE ("Rdd32 = neg ( Rss32 )"                  , "1000 0000  100sssss  PP------ 1 01ddddd"    , 0xc, 0, 0) /* A2_negp */
HEXAGON_OPCODE ("Rdd32 = not ( Rss32 )"                  , "1000 0000  100sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* A2_notp */
HEXAGON_OPCODE ("Rdd32 = or ( Rss32 , Rtt32 )"           , "1101 0011  111sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_orp */
HEXAGON_OPCODE ("Rdd32 = or ( Rtt32 , ~ Rss32 )"         , "1101 0011  111sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A4_ornp */
HEXAGON_OPCODE ("Rdd32 = packhl ( Rs32 , Rt32 ) :deprecated" , "1101 0100  --0sssss  PP-ttttt ---ddddd"     , 0xc, 0, 0) /* dep_S2_packhl */
HEXAGON_OPCODE ("Rdd32 = packhl ( Rs32 , Rt32 )"         , "1111 0101  1--sssss  PP-ttttt ---ddddd"     , 0xf, 0, 0) /* S2_packhl */
HEXAGON_OPCODE ("Rdd32 = pmpyw ( Rs32 , Rt32 )"          , "11100101010sssss  PP0ttttt 111ddddd"        , 0xc, 0, 0) /* M4_pmpyw */
HEXAGON_OPCODE ("Rdd32 = shuffeb ( Rss32 , Rtt32 )"      , "1100 0001  00-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_shuffeb */
HEXAGON_OPCODE ("Rdd32 = shuffeh ( Rss32 , Rtt32 )"      , "1100 0001  00-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_shuffeh */
HEXAGON_OPCODE ("Rdd32 = shuffob ( Rtt32 , Rss32 )"      , "1100 0001  00-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_shuffob */
HEXAGON_OPCODE ("Rdd32 = shuffoh ( Rtt32 , Rss32 )"      , "1100 0001  10-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_shuffoh */
HEXAGON_OPCODE ("Rdd32 = sub ( Rss32 , Rtt32 , Px4 ) :carry" , "1100 0010  111sssss  PP-ttttt -xxddddd"     , 0xc, 0, 0|A_LATEPRED) /* A4_subp_c */
HEXAGON_OPCODE ("Rdd32 = sub ( Rtt32 , Rss32 )"          , "1101 0011  001sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A2_subp */
HEXAGON_OPCODE ("Rdd32 = sxtw ( Rs32 )"                  , "1000 0100  01-sssss  PP------ 00-ddddd"     , 0xc, 0, 0) /* A2_sxtw */
HEXAGON_OPCODE ("Rdd32 = tlbr ( Rs32 )"                  , "0110 1100 010sssss PP------ ---ddddd"       , 0x8, 0, 0|A_SOLO) /* Y2_tlbr */
HEXAGON_OPCODE ("Rdd32 = vabsdiffh ( Rtt32 , Rss32 )"    , "11101000011sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_vabsdiffh */
HEXAGON_OPCODE ("Rdd32 = vabsdiffw ( Rtt32 , Rss32 )"    , "11101000001sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_vabsdiffw */
HEXAGON_OPCODE ("Rdd32 = vabsh ( Rss32 ) :sat"           , "1000 0000  010sssss  PP------ 1 01ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vabshsat */
HEXAGON_OPCODE ("Rdd32 = vabsh ( Rss32 )"                , "1000 0000  010sssss  PP------ 1 00ddddd"    , 0xc, 0, 0) /* A2_vabsh */
HEXAGON_OPCODE ("Rdd32 = vabsw ( Rss32 ) :sat"           , "1000 0000  010sssss  PP------ 1 11ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vabswsat */
HEXAGON_OPCODE ("Rdd32 = vabsw ( Rss32 )"                , "1000 0000  010sssss  PP------ 1 10ddddd"    , 0xc, 0, 0) /* A2_vabsw */
HEXAGON_MAPPING ("Rdd32 = vaddb ( Rss32 , Rtt32 )"        , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(A2_vaddb_map)) /* mapped to Rdd32=vaddub(Rss32,Rtt32) */
HEXAGON_OPCODE ("Rdd32 = vaddh ( Rss32 , Rtt32 ) :sat"   , "1101 0011  000sssss  PP-ttttt 011ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vaddhs */
HEXAGON_OPCODE ("Rdd32 = vaddh ( Rss32 , Rtt32 )"        , "1101 0011  000sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vaddh */
HEXAGON_OPCODE ("Rdd32 = vaddub ( Rss32 , Rtt32 ) :sat"  , "1101 0011  000sssss  PP-ttttt 001ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vaddubs */
HEXAGON_OPCODE ("Rdd32 = vaddub ( Rss32 , Rtt32 )"       , "1101 0011  000sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vaddub */
HEXAGON_OPCODE ("Rdd32 = vadduh ( Rss32 , Rtt32 ) :sat"  , "1101 0011  000sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vadduhs */
HEXAGON_OPCODE ("Rdd32 = vaddw ( Rss32 , Rtt32 ) :sat"   , "1101 0011  000sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vaddws */
HEXAGON_OPCODE ("Rdd32 = vaddw ( Rss32 , Rtt32 )"        , "1101 0011  000sssss  PP-ttttt 101ddddd"     , 0xc, 0, 0) /* A2_vaddw */
HEXAGON_OPCODE ("Rdd32 = valignb ( Rtt32 , Rss32 , #u3 )" , "1100 0000  0--sssss  PP-ttttt iiiddddd"     , 0xc, 0, 0) /* S2_valignib */
HEXAGON_OPCODE ("Rdd32 = valignb ( Rtt32 , Rss32 , Pu4 )" , "1100 0010  0--sssss  PP-ttttt -uuddddd"     , 0xc, 0, 0) /* S2_valignrb */
HEXAGON_OPCODE ("Rdd32 = vaslh ( Rss32 , #u4 )"          , "1000 0000 100sssss PP00iiii 010ddddd"       , 0xc, 0, 0) /* S2_asl_i_vh */
HEXAGON_OPCODE ("Rdd32 = vaslh ( Rss32 , Rt32 )"         , "1100 0011  01-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_asl_r_vh */
HEXAGON_OPCODE ("Rdd32 = vaslw ( Rss32 , #u5 )"          , "1000 0000 010sssss PP0iiiii 010ddddd"       , 0xc, 0, 0) /* S2_asl_i_vw */
HEXAGON_OPCODE ("Rdd32 = vaslw ( Rss32 , Rt32 )"         , "1100 0011  00-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_asl_r_vw */
HEXAGON_OPCODE ("Rdd32 = vasrh ( Rss32 , #u4 ) :raw"     , "1000 0000 001sssss PP00iiii 0 00ddddd"      , 0xc, 0, 0) /* S5_vasrhrnd */
HEXAGON_MAPPING ("Rdd32 = vasrh ( Rss32 , #u4 ) :rnd"     , "0000dddddsssssiiii00000000000000"           , HEXAGON_MAP_FNAME(S5_vasrhrnd_goodsyntax)) /* mapped to Rdd32=Rss32 or Rdd32=vasrh(Rss32,#u4-1):raw */
HEXAGON_OPCODE ("Rdd32 = vasrh ( Rss32 , #u4 )"          , "1000 0000 100sssss PP00iiii 000ddddd"       , 0xc, 0, 0) /* S2_asr_i_vh */
HEXAGON_OPCODE ("Rdd32 = vasrh ( Rss32 , Rt32 )"         , "1100 0011  01-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_asr_r_vh */
HEXAGON_OPCODE ("Rdd32 = vasrw ( Rss32 , #u5 )"          , "1000 0000 010sssss PP0iiiii 000ddddd"       , 0xc, 0, 0) /* S2_asr_i_vw */
HEXAGON_OPCODE ("Rdd32 = vasrw ( Rss32 , Rt32 )"         , "1100 0011  00-sssss  PP-ttttt 00-ddddd"     , 0xc, 0, 0) /* S2_asr_r_vw */
HEXAGON_OPCODE ("Rdd32 = vavgh ( Rss32 , Rtt32 ) :crnd"  , "1101 0011  010sssss  PP-ttttt 100ddddd"     , 0xc, 0, 0) /* A2_vavghcr */
HEXAGON_OPCODE ("Rdd32 = vavgh ( Rss32 , Rtt32 ) :rnd"   , "1101 0011  010sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_vavghr */
HEXAGON_OPCODE ("Rdd32 = vavgh ( Rss32 , Rtt32 )"        , "1101 0011  010sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vavgh */
HEXAGON_OPCODE ("Rdd32 = vavgub ( Rss32 , Rtt32 ) :rnd"  , "1101 0011  010sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_vavgubr */
HEXAGON_OPCODE ("Rdd32 = vavgub ( Rss32 , Rtt32 )"       , "1101 0011  010sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vavgub */
HEXAGON_OPCODE ("Rdd32 = vavguh ( Rss32 , Rtt32 ) :rnd"  , "1101 0011  010sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* A2_vavguhr */
HEXAGON_OPCODE ("Rdd32 = vavguh ( Rss32 , Rtt32 )"       , "1101 0011  010sssss  PP-ttttt 101ddddd"     , 0xc, 0, 0) /* A2_vavguh */
HEXAGON_OPCODE ("Rdd32 = vavguw ( Rss32 , Rtt32 ) :rnd"  , "1101 0011  011sssss  PP-ttttt 100ddddd"     , 0xc, 0, 0) /* A2_vavguwr */
HEXAGON_OPCODE ("Rdd32 = vavguw ( Rss32 , Rtt32 )"       , "1101 0011  011sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_vavguw */
HEXAGON_OPCODE ("Rdd32 = vavgw ( Rss32 , Rtt32 ) :crnd"  , "1101 0011  011sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vavgwcr */
HEXAGON_OPCODE ("Rdd32 = vavgw ( Rss32 , Rtt32 ) :rnd"   , "1101 0011  011sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_vavgwr */
HEXAGON_OPCODE ("Rdd32 = vavgw ( Rss32 , Rtt32 )"        , "1101 0011  011sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vavgw */
HEXAGON_OPCODE ("Rdd32 = vcmpyi ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000110sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmpy_s1_sat_i */
HEXAGON_OPCODE ("Rdd32 = vcmpyi ( Rss32 , Rtt32 ) :sat"  , "11101000010sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmpy_s0_sat_i */
HEXAGON_OPCODE ("Rdd32 = vcmpyr ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000101sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmpy_s1_sat_r */
HEXAGON_OPCODE ("Rdd32 = vcmpyr ( Rss32 , Rtt32 ) :sat"  , "11101000001sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmpy_s0_sat_r */
HEXAGON_OPCODE ("Rdd32 = vcnegh ( Rss32 , Rt32 )"        , "1100 0011  11-sssss  PP-ttttt 01-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vcnegh */
HEXAGON_OPCODE ("Rdd32 = vconj ( Rss32 ) :sat"           , "1000 0000  100sssss  PP------ 1 11ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vconj */
HEXAGON_OPCODE ("Rdd32 = vcrotate ( Rss32 , Rt32 )"      , "1100 0011  11-sssss  PP-ttttt 00-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vcrotate */
HEXAGON_OPCODE ("Rdd32 = vdmpy ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000100sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmpys_s1 */
HEXAGON_OPCODE ("Rdd32 = vdmpy ( Rss32 , Rtt32 ) :sat"   , "11101000000sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmpys_s0 */
HEXAGON_OPCODE ("Rdd32 = vdmpybsu ( Rss32 , Rtt32 ) :sat" , "11101000101sssss  PP0ttttt 001ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M5_vdmpybsu */
HEXAGON_OPCODE ("Rdd32 = vlslh ( Rss32 , Rt32 )"         , "1100 0011  01-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_lsl_r_vh */
HEXAGON_OPCODE ("Rdd32 = vlslw ( Rss32 , Rt32 )"         , "1100 0011  00-sssss  PP-ttttt 11-ddddd"     , 0xc, 0, 0) /* S2_lsl_r_vw */
HEXAGON_OPCODE ("Rdd32 = vlsrh ( Rss32 , #u4 )"          , "1000 0000 100sssss PP00iiii 001ddddd"       , 0xc, 0, 0) /* S2_lsr_i_vh */
HEXAGON_OPCODE ("Rdd32 = vlsrh ( Rss32 , Rt32 )"         , "1100 0011  01-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_lsr_r_vh */
HEXAGON_OPCODE ("Rdd32 = vlsrw ( Rss32 , #u5 )"          , "1000 0000 010sssss PP0iiiii 001ddddd"       , 0xc, 0, 0) /* S2_lsr_i_vw */
HEXAGON_OPCODE ("Rdd32 = vlsrw ( Rss32 , Rt32 )"         , "1100 0011  00-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_lsr_r_vw */
HEXAGON_OPCODE ("Rdd32 = vmaxb ( Rtt32 , Rss32 )"        , "1101 0011  110sssss  PP-ttttt 110ddddd"     , 0xc, 0, 0) /* A2_vmaxb */
HEXAGON_OPCODE ("Rdd32 = vmaxh ( Rtt32 , Rss32 )"        , "1101 0011  110sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_vmaxh */
HEXAGON_OPCODE ("Rdd32 = vmaxub ( Rtt32 , Rss32 )"       , "1101 0011  110sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vmaxub */
HEXAGON_OPCODE ("Rdd32 = vmaxuh ( Rtt32 , Rss32 )"       , "1101 0011  110sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vmaxuh */
HEXAGON_OPCODE ("Rdd32 = vmaxuw ( Rtt32 , Rss32 )"       , "1101 0011  101sssss  PP-ttttt 101ddddd"     , 0xc, 0, 0) /* A2_vmaxuw */
HEXAGON_OPCODE ("Rdd32 = vmaxw ( Rtt32 , Rss32 )"        , "1101 0011  110sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_vmaxw */
HEXAGON_OPCODE ("Rdd32 = vminb ( Rtt32 , Rss32 )"        , "1101 0011  110sssss  PP-ttttt 111ddddd"     , 0xc, 0, 0) /* A2_vminb */
HEXAGON_OPCODE ("Rdd32 = vminh ( Rtt32 , Rss32 )"        , "1101 0011  101sssss  PP-ttttt 001ddddd"     , 0xc, 0, 0) /* A2_vminh */
HEXAGON_OPCODE ("Rdd32 = vminub ( Rtt32 , Rss32 )"       , "1101 0011  101sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vminub */
HEXAGON_OPCODE ("Rdd32 = vminuh ( Rtt32 , Rss32 )"       , "1101 0011  101sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vminuh */
HEXAGON_OPCODE ("Rdd32 = vminuw ( Rtt32 , Rss32 )"       , "1101 0011  101sssss  PP-ttttt 100ddddd"     , 0xc, 0, 0) /* A2_vminuw */
HEXAGON_OPCODE ("Rdd32 = vminw ( Rtt32 , Rss32 )"        , "1101 0011  101sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_vminw */
HEXAGON_OPCODE ("Rdd32 = vmpybsu ( Rs32 , Rt32 )"        , "11100101010sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M5_vmpybsu */
HEXAGON_OPCODE ("Rdd32 = vmpybu ( Rs32 , Rt32 )"         , "11100101100sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M5_vmpybuu */
HEXAGON_OPCODE ("Rdd32 = vmpyeh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000100sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2es_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpyeh ( Rss32 , Rtt32 ) :sat"  , "11101000000sssss  PP0ttttt 110ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2es_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpyh ( Rs32 , Rt32 ) :<<1 :sat" , "11100101100sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2s_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpyh ( Rs32 , Rt32 ) :sat"     , "11100101000sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2s_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpyhsu ( Rs32 , Rt32 ) :<<1 :sat" , "11100101100sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2su_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpyhsu ( Rs32 , Rt32 ) :sat"   , "11100101000sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmpy2su_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpyweh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101000101sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyl_rs1 */
HEXAGON_OPCODE ("Rdd32 = vmpyweh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000100sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyl_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpyweh ( Rss32 , Rtt32 ) :rnd :sat" , "11101000001sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyl_rs0 */
HEXAGON_OPCODE ("Rdd32 = vmpyweh ( Rss32 , Rtt32 ) :sat" , "11101000000sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyl_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpyweuh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101000111sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyul_rs1 */
HEXAGON_OPCODE ("Rdd32 = vmpyweuh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000110sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyul_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpyweuh ( Rss32 , Rtt32 ) :rnd :sat" , "11101000011sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyul_rs0 */
HEXAGON_OPCODE ("Rdd32 = vmpyweuh ( Rss32 , Rtt32 ) :sat" , "11101000010sssss  PP0ttttt 101ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyul_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpywoh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101000101sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyh_rs1 */
HEXAGON_OPCODE ("Rdd32 = vmpywoh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000100sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyh_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpywoh ( Rss32 , Rtt32 ) :rnd :sat" , "11101000001sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyh_rs0 */
HEXAGON_OPCODE ("Rdd32 = vmpywoh ( Rss32 , Rtt32 ) :sat" , "11101000000sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyh_s0 */
HEXAGON_OPCODE ("Rdd32 = vmpywouh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101000111sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyuh_rs1 */
HEXAGON_OPCODE ("Rdd32 = vmpywouh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101000110sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyuh_s1 */
HEXAGON_OPCODE ("Rdd32 = vmpywouh ( Rss32 , Rtt32 ) :rnd :sat" , "11101000011sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyuh_rs0 */
HEXAGON_OPCODE ("Rdd32 = vmpywouh ( Rss32 , Rtt32 ) :sat" , "11101000010sssss  PP0ttttt 111ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmpyuh_s0 */
HEXAGON_OPCODE ("Rdd32 = vmux ( Pu4 , Rss32 , Rtt32 )"   , "1101 0001  ---sssss  PP-ttttt -uuddddd"     , 0xc, 0, 0) /* C2_vmux */
HEXAGON_OPCODE ("Rdd32 = vnavgh ( Rtt32 , Rss32 ) :crnd :sat" , "1101 0011  100sssss  PP-ttttt 010ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vnavghcr */
HEXAGON_OPCODE ("Rdd32 = vnavgh ( Rtt32 , Rss32 ) :rnd :sat" , "1101 0011  100sssss  PP-ttttt 001ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vnavghr */
HEXAGON_OPCODE ("Rdd32 = vnavgh ( Rtt32 , Rss32 )"       , "1101 0011  100sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vnavgh */
HEXAGON_OPCODE ("Rdd32 = vnavgw ( Rtt32 , Rss32 ) :crnd :sat" , "1101 0011  100sssss  PP-ttttt 11-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vnavgwcr */
HEXAGON_OPCODE ("Rdd32 = vnavgw ( Rtt32 , Rss32 ) :rnd :sat" , "1101 0011  100sssss  PP-ttttt 10-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vnavgwr */
HEXAGON_OPCODE ("Rdd32 = vnavgw ( Rtt32 , Rss32 )"       , "1101 0011  100sssss  PP-ttttt 011ddddd"     , 0xc, 0, 0) /* A2_vnavgw */
HEXAGON_OPCODE ("Rdd32 = vpmpyh ( Rs32 , Rt32 )"         , "11100101110sssss  PP0ttttt 111ddddd"        , 0xc, 0, 0) /* M4_vpmpyh */
HEXAGON_OPCODE ("Rdd32 = vraddub ( Rss32 , Rtt32 )"      , "11101000010sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* A2_vraddub */
HEXAGON_OPCODE ("Rdd32 = vrcmpyi ( Rss32 , Rtt32 )"      , "11101000000sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_vrcmpyi_s0 */
HEXAGON_OPCODE ("Rdd32 = vrcmpyi ( Rss32 , Rtt32 * )"    , "11101000010sssss  PP0ttttt 000ddddd"        , 0xc, 0, 0) /* M2_vrcmpyi_s0c */
HEXAGON_OPCODE ("Rdd32 = vrcmpyr ( Rss32 , Rtt32 )"      , "11101000000sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_vrcmpyr_s0 */
HEXAGON_OPCODE ("Rdd32 = vrcmpyr ( Rss32 , Rtt32 * )"    , "11101000011sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M2_vrcmpyr_s0c */
HEXAGON_MAPPING ("Rdd32 = vrcmpys ( Rss32 , Rt32 ) :<<1 :sat" , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(M2_vrcmpys_s1)) /* mapped to Rdd32=vrcmpys(Rss32,Rtt32):<<1:sat:raw:hi or Rdd32=vrcmpys(Rss32,Rtt32):<<1:sat:raw:lo */
HEXAGON_OPCODE ("Rdd32 = vrcmpys ( Rss32 , Rtt32 ) :<<1 :sat :raw :hi" , "11101000101sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_s1_h */
HEXAGON_OPCODE ("Rdd32 = vrcmpys ( Rss32 , Rtt32 ) :<<1 :sat :raw :lo" , "11101000111sssss  PP0ttttt 100ddddd"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_s1_l */
HEXAGON_OPCODE ("Rdd32 = vrcrotate ( Rss32 , Rt32 , #u2 )" , "1100 0011  11-sssss  PPittttt 11iddddd"     , 0xc, 0, 0) /* S4_vrcrotate */
HEXAGON_OPCODE ("Rdd32 = vrmpybsu ( Rss32 , Rtt32 )"     , "11101000110sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M5_vrmpybsu */
HEXAGON_OPCODE ("Rdd32 = vrmpybu ( Rss32 , Rtt32 )"      , "11101000100sssss  PP0ttttt 001ddddd"        , 0xc, 0, 0) /* M5_vrmpybuu */
HEXAGON_OPCODE ("Rdd32 = vrmpyh ( Rss32 , Rtt32 )"       , "11101000000sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* M2_vrmpy_s0 */
HEXAGON_OPCODE ("Rdd32 = vrmpyweh ( Rss32 , Rtt32 ) :<<1" , "11101000110sssss  PP0ttttt 100ddddd"        , 0xc, 0, 0) /* M4_vrmpyeh_s1 */
HEXAGON_OPCODE ("Rdd32 = vrmpyweh ( Rss32 , Rtt32 )"     , "11101000010sssss  PP0ttttt 100ddddd"        , 0xc, 0, 0) /* M4_vrmpyeh_s0 */
HEXAGON_OPCODE ("Rdd32 = vrmpywoh ( Rss32 , Rtt32 ) :<<1" , "11101000101sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* M4_vrmpyoh_s1 */
HEXAGON_OPCODE ("Rdd32 = vrmpywoh ( Rss32 , Rtt32 )"     , "11101000001sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* M4_vrmpyoh_s0 */
HEXAGON_OPCODE ("Rdd32 = vrsadub ( Rss32 , Rtt32 )"      , "11101000010sssss  PP0ttttt 010ddddd"        , 0xc, 0, 0) /* A2_vrsadub */
HEXAGON_OPCODE ("Rdd32 = vsathb ( Rss32 )"               , "1000 0000  000sssss  PP------ 1 11ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsathb_nopack */
HEXAGON_OPCODE ("Rdd32 = vsathub ( Rss32 )"              , "1000 0000  000sssss  PP------ 1 00ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsathub_nopack */
HEXAGON_OPCODE ("Rdd32 = vsatwh ( Rss32 )"               , "1000 0000  000sssss  PP------ 1 10ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsatwh_nopack */
HEXAGON_OPCODE ("Rdd32 = vsatwuh ( Rss32 )"              , "1000 0000  000sssss  PP------ 1 01ddddd"    , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S2_vsatwuh_nopack */
HEXAGON_OPCODE ("Rdd32 = vsplath ( Rs32 )"               , "1000 0100  01-sssss  PP------ 01-ddddd"     , 0xc, 0, 0) /* S2_vsplatrh */
HEXAGON_OPCODE ("Rdd32 = vspliceb ( Rss32 , Rtt32 , #u3 )" , "1100 0000  1--sssss  PP-ttttt iiiddddd"     , 0xc, 0, 0) /* S2_vspliceib */
HEXAGON_OPCODE ("Rdd32 = vspliceb ( Rss32 , Rtt32 , Pu4 )" , "1100 0010  10-sssss  PP-ttttt -uuddddd"     , 0xc, 0, 0) /* S2_vsplicerb */
HEXAGON_MAPPING ("Rdd32 = vsubb ( Rss32 , Rtt32 )"        , "0000dddddsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(A2_vsubb_map)) /* mapped to Rdd32=vsubub(Rss32,Rtt32) */
HEXAGON_OPCODE ("Rdd32 = vsubh ( Rtt32 , Rss32 ) :sat"   , "1101 0011  001sssss  PP-ttttt 011ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vsubhs */
HEXAGON_OPCODE ("Rdd32 = vsubh ( Rtt32 , Rss32 )"        , "1101 0011  001sssss  PP-ttttt 010ddddd"     , 0xc, 0, 0) /* A2_vsubh */
HEXAGON_OPCODE ("Rdd32 = vsubub ( Rtt32 , Rss32 ) :sat"  , "1101 0011  001sssss  PP-ttttt 001ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vsububs */
HEXAGON_OPCODE ("Rdd32 = vsubub ( Rtt32 , Rss32 )"       , "1101 0011  001sssss  PP-ttttt 000ddddd"     , 0xc, 0, 0) /* A2_vsubub */
HEXAGON_OPCODE ("Rdd32 = vsubuh ( Rtt32 , Rss32 ) :sat"  , "1101 0011  001sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vsubuhs */
HEXAGON_OPCODE ("Rdd32 = vsubw ( Rtt32 , Rss32 ) :sat"   , "1101 0011  001sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* A2_vsubws */
HEXAGON_OPCODE ("Rdd32 = vsubw ( Rtt32 , Rss32 )"        , "1101 0011  001sssss  PP-ttttt 101ddddd"     , 0xc, 0, 0) /* A2_vsubw */
HEXAGON_OPCODE ("Rdd32 = vsxtbh ( Rs32 )"                , "1000 0100  00-sssss  PP------ 00-ddddd"     , 0xc, 0, 0) /* S2_vsxtbh */
HEXAGON_OPCODE ("Rdd32 = vsxthw ( Rs32 )"                , "1000 0100  00-sssss  PP------ 10-ddddd"     , 0xc, 0, 0) /* S2_vsxthw */
HEXAGON_OPCODE ("Rdd32 = vtrunewh ( Rss32 , Rtt32 )"     , "1100 0001  10-sssss  PP-ttttt 01-ddddd"     , 0xc, 0, 0) /* S2_vtrunewh */
HEXAGON_OPCODE ("Rdd32 = vtrunowh ( Rss32 , Rtt32 )"     , "1100 0001  10-sssss  PP-ttttt 10-ddddd"     , 0xc, 0, 0) /* S2_vtrunowh */
HEXAGON_OPCODE ("Rdd32 = vxaddsubh ( Rss32 , Rtt32 ) :rnd :>>1 :sat" , "1100 0001  11-sssss  PP-ttttt 00-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxaddsubhr */
HEXAGON_OPCODE ("Rdd32 = vxaddsubh ( Rss32 , Rtt32 ) :sat" , "1100 0001  01-sssss  PP-ttttt 100ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxaddsubh */
HEXAGON_OPCODE ("Rdd32 = vxaddsubw ( Rss32 , Rtt32 ) :sat" , "1100 0001  01-sssss  PP-ttttt 000ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxaddsubw */
HEXAGON_OPCODE ("Rdd32 = vxsubaddh ( Rss32 , Rtt32 ) :rnd :>>1 :sat" , "1100 0001  11-sssss  PP-ttttt 01-ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxsubaddhr */
HEXAGON_OPCODE ("Rdd32 = vxsubaddh ( Rss32 , Rtt32 ) :sat" , "1100 0001  01-sssss  PP-ttttt 110ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxsubaddh */
HEXAGON_OPCODE ("Rdd32 = vxsubaddw ( Rss32 , Rtt32 ) :sat" , "1100 0001  01-sssss  PP-ttttt 010ddddd"     , 0xc, 0|IMPLICIT_SR_OVF, 0) /* S4_vxsubaddw */
HEXAGON_OPCODE ("Rdd32 = vzxtbh ( Rs32 )"                , "1000 0100  00-sssss  PP------ 01-ddddd"     , 0xc, 0, 0) /* S2_vzxtbh */
HEXAGON_OPCODE ("Rdd32 = vzxthw ( Rs32 )"                , "1000 0100  00-sssss  PP------ 11-ddddd"     , 0xc, 0, 0) /* S2_vzxthw */
HEXAGON_OPCODE ("Rdd32 = xor ( Rss32 , Rtt32 )"          , "1101 0011  111sssss  PP-ttttt 100ddddd"     , 0xc, 0, 0) /* A2_xorp */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; allocframe ( #u5:3 )" , "011111-0-II00dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-0-II00dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-0-II00dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-0-II00dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-0-II00dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-0-II00dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-0-II00dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-0-II00dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-0-II00dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #U2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-0-II00dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; dealloc_return" , "010111-0-ii00dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine0i_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; deallocframe" , "010111-0-ii00dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( ! p0 ) dealloc_return" , "010111-0-ii00dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine0i_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( ! p0 ) jumpr Lr" , "010111-0-ii00dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-0-ii00dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine0i_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-0-ii00dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( p0 ) dealloc_return" , "010111-0-ii00dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine0i_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( p0 ) jumpr Lr" , "010111-0-ii00dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-0-ii00dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine0i_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-0-ii00dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , #u2 ) ; jumpr Lr" , "010111-0-ii00dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; allocframe ( #u5:3 )" , "011111-1ssss0dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; dealloc_return" , "010111-1ssss0dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinezr_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; deallocframe" , "010111-1ssss0dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( ! p0 ) dealloc_return" , "010111-1ssss0dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinezr_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( ! p0 ) jumpr Lr" , "010111-1ssss0dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-1ssss0dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinezr_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-1ssss0dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( p0 ) dealloc_return" , "010111-1ssss0dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinezr_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( p0 ) jumpr Lr" , "010111-1ssss0dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-1ssss0dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinezr_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-1ssss0dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; jumpr Lr" , "010111-1ssss0dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-1ssss0dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Rs16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-1ssss0dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-1uuuu0dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-1uuuu0dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-1uuuu0dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-1uuuu0dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-1uuuu0dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-1uuuu0dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #0 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-1uuuu0dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; allocframe ( #u5:3 )" , "011111-0-II01dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-0-II01dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-0-II01dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-0-II01dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-0-II01dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-0-II01dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-0-II01dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-0-II01dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-0-II01dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #U2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-0-II01dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; dealloc_return" , "010111-0-ii01dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine1i_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; deallocframe" , "010111-0-ii01dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( ! p0 ) dealloc_return" , "010111-0-ii01dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine1i_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( ! p0 ) jumpr Lr" , "010111-0-ii01dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-0-ii01dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine1i_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-0-ii01dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( p0 ) dealloc_return" , "010111-0-ii01dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine1i_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( p0 ) jumpr Lr" , "010111-0-ii01dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-0-ii01dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine1i_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-0-ii01dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #1 , #u2 ) ; jumpr Lr" , "010111-0-ii01dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; allocframe ( #u5:3 )" , "011111-0-II10dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-0-II10dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-0-II10dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-0-II10dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-0-II10dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-0-II10dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-0-II10dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-0-II10dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-0-II10dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #U2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-0-II10dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; dealloc_return" , "010111-0-ii10dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine2i_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; deallocframe" , "010111-0-ii10dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( ! p0 ) dealloc_return" , "010111-0-ii10dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine2i_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( ! p0 ) jumpr Lr" , "010111-0-ii10dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-0-ii10dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine2i_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-0-ii10dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( p0 ) dealloc_return" , "010111-0-ii10dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine2i_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( p0 ) jumpr Lr" , "010111-0-ii10dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-0-ii10dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine2i_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-0-ii10dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #2 , #u2 ) ; jumpr Lr" , "010111-0-ii10dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; allocframe ( #u5:3 )" , "011111-0-II11dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-0-II11dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-0-II11dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-0-II11dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-0-II11dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-0-II11dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-0-II11dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-0-II11dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-0-II11dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #U2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-0-II11dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; dealloc_return" , "010111-0-ii11dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine3i_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; deallocframe" , "010111-0-ii11dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( ! p0 ) dealloc_return" , "010111-0-ii11dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine3i_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( ! p0 ) jumpr Lr" , "010111-0-ii11dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-0-ii11dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine3i_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-0-ii11dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( p0 ) dealloc_return" , "010111-0-ii11dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine3i_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( p0 ) jumpr Lr" , "010111-0-ii11dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-0-ii11dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combine3i_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-0-ii11dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( #3 , #u2 ) ; jumpr Lr" , "010111-0-ii11dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; allocframe ( #u5:3 )" , "011111-1ssss1dddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; dealloc_return" , "010111-1ssss1dddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinerz_SL2_return */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; deallocframe" , "010111-1ssss1dddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( ! p0 ) dealloc_return" , "010111-1ssss1dddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinerz_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( ! p0 ) jumpr Lr" , "010111-1ssss1dddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( ! p0 .new ) dealloc_return:nt" , "010111-1ssss1dddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinerz_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "010111-1ssss1dddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( p0 ) dealloc_return" , "010111-1ssss1dddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinerz_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( p0 ) jumpr Lr" , "010111-1ssss1dddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( p0 .new ) dealloc_return:nt" , "010111-1ssss1dddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_combinerz_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; if ( p0 .new ) jumpr:nt Lr" , "010111-1ssss1dddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; jumpr Lr" , "010111-1ssss1dddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_jumpr31 */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "011111-1ssss1dddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( Rs16 , #0 ) ; memw ( Sp + #u5:2 ) = Rt16" , "011111-1ssss1dddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memb ( Rs16 + #u4:0 ) = #0" , "011111-1uuuu1dddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memb ( Rs16 + #u4:0 ) = #1" , "011111-1uuuu1dddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "011111-1uuuu1dddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "011111-1uuuu1dddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memw ( Rs16 + #u4:2 ) = #0" , "011111-1uuuu1dddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memw ( Rs16 + #u4:2 ) = #1" , "011111-1uuuu1dddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = combine ( Ru16 , #0 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "011111-1uuuu1dddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; allocframe ( #u5:3 )" , "11011110IIIIIdddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_allocframe */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memb ( Rs16 + #u4:0 ) = #0" , "11011110IIIIIdddEE110010ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storebi0 */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memb ( Rs16 + #u4:0 ) = #1" , "11011110IIIIIdddEE110011ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storebi1 */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "10011110IIIIIdddEE11iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS1_storeb_io */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "11011110IIIIIdddEE10101iiiiiittt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_stored_sp */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "11011110IIIIIdddEE100iiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storeh_io */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memw ( Rs16 + #u4:2 ) = #0" , "11011110IIIIIdddEE110000ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storewi0 */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memw ( Rs16 + #u4:2 ) = #1" , "11011110IIIIIdddEE110001ssssiiii"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storewi1 */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "10011110IIIIIdddEE10iiiisssstttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS1_storew_io */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #U5:3 ) ; memw ( Sp + #u5:2 ) = Rt16" , "11011110IIIIIdddEE10100iiiiitttt"           , 0x1, 0, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SS2_storew_sp */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; dealloc_return" , "00111110iiiiidddEE01111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_return */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; deallocframe" , "00111110iiiiidddEE01111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_deallocframe */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( ! p0 ) dealloc_return" , "00111110iiiiidddEE01111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_return_f */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( ! p0 ) jumpr Lr" , "00111110iiiiidddEE01111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( ! p0 .new ) dealloc_return:nt" , "00111110iiiiidddEE01111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_return_fnew */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "00111110iiiiidddEE01111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( p0 ) dealloc_return" , "00111110iiiiidddEE01111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_return_t */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( p0 ) jumpr Lr" , "00111110iiiiidddEE01111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( p0 .new ) dealloc_return:nt" , "00111110iiiiidddEE01111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_return_tnew */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; if ( p0 .new ) jumpr:nt Lr" , "00111110iiiiidddEE01111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rdd8 = memd ( Sp + #u5:3 ) ; jumpr Lr"  , "00111110iiiiidddEE01111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_jumpr31 */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = #-1"                , "0011101--0--eeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memb ( Rs16 + #u3:0 )" , "0101101--0--eeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memh ( Rs16 + #u3:1 )" , "0101101--0--eeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memub ( Rs16 + #u4:0 )" , "0101101--0--eeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0101101--0--eeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memw ( Rs16 + #u4:2 )" , "0101101--0--eeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = #-1 ; Rd16 = memw ( Sp + #u5:2 )" , "0101101--0--eeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( #0 , #u2 )" , "0011101--0--eeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( #0 , Rs16 )" , "0011101--0--eeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( #1 , #u2 )" , "0011101--0--eeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( #2 , #u2 )" , "0011101--0--eeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( #3 , #u2 )" , "0011101--0--eeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = combine ( Rs16 , #0 )" , "0011101--0--eeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = #-1 ; Rdd8 = memd ( Sp + #u5:3 )" , "0101101--0--eeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = #-1 ; if ( ! p0 ) Rd16 = #0"     , "0011101--0--eeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_clrf */
HEXAGON_OPCODE ("Re16 = #-1 ; if ( ! p0 .new ) Rd16 = #0" , "0011101--0--eeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = #-1 ; if ( p0 ) Rd16 = #0"       , "0011101--0--eeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_clrt */
HEXAGON_OPCODE ("Re16 = #-1 ; if ( p0 .new ) Rd16 = #0"  , "0011101--0--eeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_setin1_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = #-1"                , "001010IIIIIIeeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = #u6"                , "001010IIIIIIeeeeEE1010iiiiiidddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_seti */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = add ( Rs16 , #-1 )" , "001010IIIIIIeeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_dec */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = add ( Rs16 , #1 )"  , "001010IIIIIIeeeeEE110001ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_inc */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = add ( Sp , #u6:2 )" , "001010IIIIIIeeeeEE1011iiiiiidddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_addsp */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = and ( Rs16 , #1 )"  , "001010IIIIIIeeeeEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_and1 */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = and ( Rs16 , #255 )" , "001010IIIIIIeeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memb ( Rs16 + #u3:0 )" , "010010IIIIIIeeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memh ( Rs16 + #u3:1 )" , "010010IIIIIIeeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memub ( Rs16 + #u4:0 )" , "010010IIIIIIeeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010010IIIIIIeeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memw ( Rs16 + #u4:2 )" , "010010IIIIIIeeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = #U6 ; Rd16 = memw ( Sp + #u5:2 )" , "010010IIIIIIeeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( #0 , #u2 )" , "001010IIIIIIeeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( #0 , Rs16 )" , "001010IIIIIIeeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( #1 , #u2 )" , "001010IIIIIIeeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( #2 , #u2 )" , "001010IIIIIIeeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( #3 , #u2 )" , "001010IIIIIIeeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = combine ( Rs16 , #0 )" , "001010IIIIIIeeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = #U6 ; Rdd8 = memd ( Sp + #u5:3 )" , "010010IIIIIIeeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = #U6 ; if ( ! p0 ) Rd16 = #0"     , "001010IIIIIIeeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_clrf */
HEXAGON_OPCODE ("Re16 = #U6 ; if ( ! p0 .new ) Rd16 = #0" , "001010IIIIIIeeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = #U6 ; if ( p0 ) Rd16 = #0"       , "001010IIIIIIeeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_clrt */
HEXAGON_OPCODE ("Re16 = #U6 ; if ( p0 .new ) Rd16 = #0"  , "001010IIIIIIeeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = #u6 ; Rd16 = Rs16"               , "001010iiiiiieeeeEE110000ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_tfr */
HEXAGON_OPCODE ("Re16 = #u6 ; Rd16 = sxtb ( Rs16 )"      , "001010iiiiiieeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = #u6 ; Rd16 = sxth ( Rs16 )"      , "001010iiiiiieeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_sxth */
HEXAGON_OPCODE ("Re16 = #u6 ; Rd16 = zxth ( Rs16 )"      , "001010iiiiiieeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_seti_SA1_zxth */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rd16 = #-1"               , "00110000sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rd16 = memw ( Sp + #u5:2 )" , "01010000sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rdd8 = combine ( #0 , #u2 )" , "00110000sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rdd8 = combine ( #1 , #u2 )" , "00110000sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rdd8 = combine ( #2 , #u2 )" , "00110000sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rdd8 = combine ( #3 , #u2 )" , "00110000sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = Rs16 ; Rdd8 = memd ( Sp + #u5:3 )" , "01010000sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = Rs16 ; if ( ! p0 ) Rd16 = #0"    , "00110000sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_clrf */
HEXAGON_OPCODE ("Re16 = Rs16 ; if ( ! p0 .new ) Rd16 = #0" , "00110000sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = Rs16 ; if ( p0 ) Rd16 = #0"      , "00110000sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_clrt */
HEXAGON_OPCODE ("Re16 = Rs16 ; if ( p0 .new ) Rd16 = #0" , "00110000sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = Rs16"              , "00110000uuuueeeeEE110000ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_tfr */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = add ( Rs16 , #-1 )" , "00110000uuuueeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_dec */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = add ( Rs16 , #1 )" , "00110000uuuueeeeEE110001ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_inc */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = and ( Rs16 , #1 )" , "00110000uuuueeeeEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_and1 */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = and ( Rs16 , #255 )" , "00110000uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010000uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010000uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010000uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010000uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010000uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = sxtb ( Rs16 )"     , "00110000uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = sxth ( Rs16 )"     , "00110000uuuueeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_sxth */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rd16 = zxth ( Rs16 )"     , "00110000uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_zxth */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rdd8 = combine ( #0 , Rs16 )" , "00110000uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = Ru16 ; Rdd8 = combine ( Rs16 , #0 )" , "00110000uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_tfr_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rd16 = #-1" , "00110011sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010011sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110011sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110011sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110011sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110011sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010011sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; if ( ! p0 ) Rd16 = #0" , "00110011sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_clrf */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110011sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; if ( p0 ) Rd16 = #0" , "00110011sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_clrt */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #-1 ) ; if ( p0 .new ) Rd16 = #0" , "00110011sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rd16 = #-1"  , "00110001sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010001sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110001sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110001sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110001sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110001sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010001sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; if ( ! p0 ) Rd16 = #0" , "00110001sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_clrf */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110001sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; if ( p0 ) Rd16 = #0" , "00110001sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_clrt */
HEXAGON_OPCODE ("Re16 = add ( Rs16 , #1 ) ; if ( p0 .new ) Rd16 = #0" , "00110001sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = add ( Rs16 , #-1 )" , "00110011uuuueeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_dec */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = and ( Rs16 , #255 )" , "00110011uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010011uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010011uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010011uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010011uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010011uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = sxtb ( Rs16 )" , "00110011uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = sxth ( Rs16 )" , "00110011uuuueeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_sxth */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rd16 = zxth ( Rs16 )" , "00110011uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_zxth */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110011uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #-1 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110011uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_dec_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = add ( Rs16 , #-1 )" , "00110001uuuueeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_dec */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = add ( Rs16 , #1 )" , "00110001uuuueeeeEE110001ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_inc */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = and ( Rs16 , #1 )" , "00110001uuuueeeeEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_and1 */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = and ( Rs16 , #255 )" , "00110001uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010001uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010001uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010001uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010001uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010001uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = sxtb ( Rs16 )" , "00110001uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = sxth ( Rs16 )" , "00110001uuuueeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_sxth */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rd16 = zxth ( Rs16 )" , "00110001uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_zxth */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110001uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = add ( Ru16 , #1 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110001uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_inc_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = #-1" , "001011IIIIIIeeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = add ( Rs16 , #-1 )" , "001011IIIIIIeeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_dec */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = add ( Rs16 , #1 )" , "001011IIIIIIeeeeEE110001ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_inc */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = add ( Sp , #u6:2 )" , "001011IIIIIIeeeeEE1011iiiiiidddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_addsp */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = and ( Rs16 , #1 )" , "001011IIIIIIeeeeEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_and1 */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = and ( Rs16 , #255 )" , "001011IIIIIIeeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010011IIIIIIeeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010011IIIIIIeeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010011IIIIIIeeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010011IIIIIIeeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010011IIIIIIeeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010011IIIIIIeeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( #0 , #u2 )" , "001011IIIIIIeeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001011IIIIIIeeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( #1 , #u2 )" , "001011IIIIIIeeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( #2 , #u2 )" , "001011IIIIIIeeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( #3 , #u2 )" , "001011IIIIIIeeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001011IIIIIIeeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010011IIIIIIeeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; if ( ! p0 ) Rd16 = #0" , "001011IIIIIIeeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_clrf */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; if ( ! p0 .new ) Rd16 = #0" , "001011IIIIIIeeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; if ( p0 ) Rd16 = #0" , "001011IIIIIIeeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_clrt */
HEXAGON_OPCODE ("Re16 = add ( Sp , #U6:2 ) ; if ( p0 .new ) Rd16 = #0" , "001011IIIIIIeeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = add ( Sp , #u6:2 ) ; Rd16 = Rs16" , "001011iiiiiieeeeEE110000ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_tfr */
HEXAGON_OPCODE ("Re16 = add ( Sp , #u6:2 ) ; Rd16 = sxtb ( Rs16 )" , "001011iiiiiieeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = add ( Sp , #u6:2 ) ; Rd16 = sxth ( Rs16 )" , "001011iiiiiieeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_sxth */
HEXAGON_OPCODE ("Re16 = add ( Sp , #u6:2 ) ; Rd16 = zxth ( Rs16 )" , "001011iiiiiieeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addsp_SA1_zxth */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rd16 = #-1"  , "00110010sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010010sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110010sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110010sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110010sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110010sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010010sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; if ( ! p0 ) Rd16 = #0" , "00110010sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_clrf */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110010sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; if ( p0 ) Rd16 = #0" , "00110010sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_clrt */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #1 ) ; if ( p0 .new ) Rd16 = #0" , "00110010sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rd16 = #-1" , "00110111sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010111sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110111sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110111sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110111sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110111sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010111sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; if ( ! p0 ) Rd16 = #0" , "00110111sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_clrf */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110111sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; if ( p0 ) Rd16 = #0" , "00110111sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_clrt */
HEXAGON_OPCODE ("Re16 = and ( Rs16 , #255 ) ; if ( p0 .new ) Rd16 = #0" , "00110111sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = add ( Rs16 , #-1 )" , "00110010uuuueeeeEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_dec */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = and ( Rs16 , #1 )" , "00110010uuuueeeeEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_and1 */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = and ( Rs16 , #255 )" , "00110010uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010010uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010010uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010010uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010010uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010010uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = sxtb ( Rs16 )" , "00110010uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = sxth ( Rs16 )" , "00110010uuuueeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_sxth */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rd16 = zxth ( Rs16 )" , "00110010uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_zxth */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110010uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #1 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110010uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_and1_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = and ( Rs16 , #255 )" , "00110111uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010111uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010111uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010111uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010111uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010111uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110111uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = and ( Ru16 , #255 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110111uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxtb_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = memb ( Rs16 + #U3:0 ) ; Rd16 = memw ( Sp + #u5:2 )" , "00110IIIsssseeeeEE01110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memb ( Rs16 + #U3:0 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "00110IIIsssseeeeEE011110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = memb ( Ru16 + #U3:0 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "00110IIIuuuueeeeEE010iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrb_io_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = memh ( Rs16 + #U3:1 ) ; Rd16 = memw ( Sp + #u5:2 )" , "00100IIIsssseeeeEE01110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memh ( Rs16 + #U3:1 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "00100IIIsssseeeeEE011110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = memh ( Ru16 + #U3:1 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "00100IIIuuuueeeeEE010iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = memh ( Ru16 + #U3:1 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "00100IIIuuuueeeeEE000iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = memh ( Ru16 + #U3:1 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "00100IIIuuuueeeeEE001iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrh_io_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = memub ( Rs16 + #U4:0 ) ; Rd16 = memw ( Sp + #u5:2 )" , "0001IIIIsssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memub ( Rs16 + #U4:0 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "0001IIIIsssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = memub ( Ru16 + #U4:0 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "0001IIIIuuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = memub ( Ru16 + #U4:0 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "0001IIIIuuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = memub ( Ru16 + #U4:0 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "0001IIIIuuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = memub ( Ru16 + #U4:0 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0001IIIIuuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadrub_io_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = memuh ( Rs16 + #U3:1 ) ; Rd16 = memw ( Sp + #u5:2 )" , "00101IIIsssseeeeEE01110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memuh ( Rs16 + #U3:1 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "00101IIIsssseeeeEE011110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = memuh ( Ru16 + #U3:1 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "00101IIIuuuueeeeEE010iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = memuh ( Ru16 + #U3:1 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "00101IIIuuuueeeeEE001iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadruh_io_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = memw ( Rs16 + #U4:2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "0000IIIIsssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memw ( Rs16 + #U4:2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "0000IIIIsssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = memw ( Ru16 + #U4:2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "0000IIIIuuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = memw ( Ru16 + #U4:2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "0000IIIIuuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = memw ( Ru16 + #U4:2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "0000IIIIuuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = memw ( Ru16 + #U4:2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0000IIIIuuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = memw ( Ru16 + #U4:2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "0000IIIIuuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL1_loadri_io_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = memw ( Sp + #U5:2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "0011110IIIIIeeeeEE01110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = memw ( Sp + #U5:2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "0011110IIIIIeeeeEE011110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadri_sp_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rd16 = #-1"      , "00110101sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010101sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110101sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110101sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110101sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110101sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010101sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; if ( ! p0 ) Rd16 = #0" , "00110101sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_clrf */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110101sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; if ( p0 ) Rd16 = #0" , "00110101sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_clrt */
HEXAGON_OPCODE ("Re16 = sxtb ( Rs16 ) ; if ( p0 .new ) Rd16 = #0" , "00110101sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = and ( Rs16 , #255 )" , "00110101uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010101uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010101uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010101uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010101uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010101uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = sxtb ( Rs16 )" , "00110101uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rd16 = zxth ( Rs16 )" , "00110101uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_zxth */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110101uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = sxtb ( Ru16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110101uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxtb_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rd16 = #-1"      , "00110100sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010100sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110100sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110100sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110100sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110100sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010100sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; if ( ! p0 ) Rd16 = #0" , "00110100sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_clrf */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110100sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; if ( p0 ) Rd16 = #0" , "00110100sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_clrt */
HEXAGON_OPCODE ("Re16 = sxth ( Rs16 ) ; if ( p0 .new ) Rd16 = #0" , "00110100sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = and ( Rs16 , #255 )" , "00110100uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010100uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010100uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010100uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010100uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010100uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = sxtb ( Rs16 )" , "00110100uuuueeeeEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_sxtb */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = sxth ( Rs16 )" , "00110100uuuueeeeEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_sxth */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rd16 = zxth ( Rs16 )" , "00110100uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_zxth */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110100uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = sxth ( Ru16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110100uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_sxth_SA1_combinerz */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rd16 = #-1"      , "00110110sssseeeeEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_setin1 */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01010110sssseeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_loadri_sp */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rdd8 = combine ( #0 , #u2 )" , "00110110sssseeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combine0i */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rdd8 = combine ( #1 , #u2 )" , "00110110sssseeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combine1i */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rdd8 = combine ( #2 , #u2 )" , "00110110sssseeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combine2i */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rdd8 = combine ( #3 , #u2 )" , "00110110sssseeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combine3i */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01010110sssseeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_loadrd_sp */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; if ( ! p0 ) Rd16 = #0" , "00110110sssseeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_clrf */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; if ( ! p0 .new ) Rd16 = #0" , "00110110sssseeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_clrfnew */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; if ( p0 ) Rd16 = #0" , "00110110sssseeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_clrt */
HEXAGON_OPCODE ("Re16 = zxth ( Rs16 ) ; if ( p0 .new ) Rd16 = #0" , "00110110sssseeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_clrtnew */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = and ( Rs16 , #255 )" , "00110110uuuueeeeEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_zxtb */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01010110uuuueeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_loadrb_io */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01010110uuuueeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_loadrh_io */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01010110uuuueeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL1_loadrub_io */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01010110uuuueeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL2_loadruh_io */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01010110uuuueeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SL1_loadri_io */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rd16 = zxth ( Rs16 )" , "00110110uuuueeeeEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_zxth */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00110110uuuueeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combinezr */
HEXAGON_OPCODE ("Re16 = zxth ( Ru16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00110110uuuueeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_zxth_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-0-II00eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-0-II00eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-0-II00eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-0-II00eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-0-II00eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-0-II00eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( #0 , #u2 )" , "001111-0-II00eeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combine0i */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001111-0-II00eeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combinezr */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( #1 , #u2 )" , "001111-0-II00eeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combine1i */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( #2 , #u2 )" , "001111-0-II00eeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combine2i */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( #3 , #u2 )" , "001111-0-II00eeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combine3i */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-0-II00eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , #U2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-0-II00eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine0i_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Rs16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-1ssss0eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Rs16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-1ssss0eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-1uuuu0eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-1uuuu0eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-1uuuu0eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-1uuuu0eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-1uuuu0eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001111-1uuuu0eeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SA1_combinezr */
HEXAGON_OPCODE ("Ree8 = combine ( #0 , Ru16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-1uuuu0eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinezr_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-0-II01eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-0-II01eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-0-II01eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-0-II01eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-0-II01eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-0-II01eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001111-0-II01eeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SA1_combinezr */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = combine ( #1 , #u2 )" , "001111-0-II01eeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SA1_combine1i */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = combine ( #2 , #u2 )" , "001111-0-II01eeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SA1_combine2i */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = combine ( #3 , #u2 )" , "001111-0-II01eeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SA1_combine3i */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-0-II01eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #1 , #U2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-0-II01eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine1i_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-0-II10eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-0-II10eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-0-II10eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-0-II10eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-0-II10eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-0-II10eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001111-0-II10eeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SA1_combinezr */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rdd8 = combine ( #2 , #u2 )" , "001111-0-II10eeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SA1_combine2i */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rdd8 = combine ( #3 , #u2 )" , "001111-0-II10eeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SA1_combine3i */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-0-II10eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #2 , #U2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-0-II10eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine2i_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-0-II11eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-0-II11eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-0-II11eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-0-II11eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-0-II11eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-0-II11eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "001111-0-II11eeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SA1_combinezr */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rdd8 = combine ( #3 , #u2 )" , "001111-0-II11eeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SA1_combine3i */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-0-II11eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = combine ( #3 , #U2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-0-II11eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combine3i_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( Rs16 , #0 ) ; Rd16 = memw ( Sp + #u5:2 )" , "010111-1ssss1eeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_loadri_sp */
HEXAGON_OPCODE ("Ree8 = combine ( Rs16 , #0 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "010111-1ssss1eeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_loadrd_sp */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "010111-1uuuu1eeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_loadrb_io */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "010111-1uuuu1eeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_loadrh_io */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "010111-1uuuu1eeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL1_loadrub_io */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "010111-1uuuu1eeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL2_loadruh_io */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "010111-1uuuu1eeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SL1_loadri_io */
HEXAGON_OPCODE ("Ree8 = combine ( Ru16 , #0 ) ; Rdd8 = combine ( Rs16 , #0 )" , "001111-1uuuu1eeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_combinerz_SA1_combinerz */
HEXAGON_OPCODE ("Ree8 = memd ( Sp + #U5:3 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "00111110IIIIIeeeEE011110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_loadrd_sp_SL2_loadrd_sp */
HEXAGON_OPCODE ("Rx32.h = #u16"                          , "0111 0010 ii1xxxxx PPiiiiii iiiiiiii"       , 0xf, 0, 0) /* A2_tfrih */
HEXAGON_OPCODE ("Rx32.l = #u16"                          , "0111 0001 ii1xxxxx PPiiiiii iiiiiiii"       , 0xf, 0, 0) /* A2_tfril */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rd16 = #-1" , "00111000ssssxxxxEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_setin1 */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01011000ssssxxxxEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_loadri_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rdd8 = combine ( #0 , #u2 )" , "00111000ssssxxxxEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combine0i */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rdd8 = combine ( #1 , #u2 )" , "00111000ssssxxxxEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combine1i */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rdd8 = combine ( #2 , #u2 )" , "00111000ssssxxxxEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combine2i */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rdd8 = combine ( #3 , #u2 )" , "00111000ssssxxxxEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combine3i */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01011000ssssxxxxEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_loadrd_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; allocframe ( #u5:3 )" , "01111000ssssxxxxEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_allocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; dealloc_return" , "01011000ssssxxxxEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_return */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; deallocframe" , "01011000ssssxxxxEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_deallocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 ) Rd16 = #0" , "00111000ssssxxxxEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_clrf */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 ) dealloc_return" , "01011000ssssxxxxEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_return_f */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 ) jumpr Lr" , "01011000ssssxxxxEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 .new ) Rd16 = #0" , "00111000ssssxxxxEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_clrfnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01011000ssssxxxxEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_return_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01011000ssssxxxxEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 ) Rd16 = #0" , "00111000ssssxxxxEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_clrt */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 ) dealloc_return" , "01011000ssssxxxxEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_return_t */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 ) jumpr Lr" , "01011000ssssxxxxEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 .new ) Rd16 = #0" , "00111000ssssxxxxEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_clrtnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 .new ) dealloc_return:nt" , "01011000ssssxxxxEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_return_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; if ( p0 .new ) jumpr:nt Lr" , "01011000ssssxxxxEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; jumpr Lr"  , "01011000ssssxxxxEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_jumpr31 */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01111000ssssxxxxEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_stored_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rs16 , Rx16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01111000ssssxxxxEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storew_sp */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01011000uuuuxxxxEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_loadrb_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01011000uuuuxxxxEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_loadrh_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01011000uuuuxxxxEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL1_loadrub_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01011000uuuuxxxxEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL2_loadruh_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01011000uuuuxxxxEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SL1_loadri_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00111000uuuuxxxxEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combinezr */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00111000uuuuxxxxEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_combinerz */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01111000uuuuxxxxEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storebi0 */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01111000uuuuxxxxEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storebi1 */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01111000uuuuxxxxEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS1_storeb_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01111000uuuuxxxxEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storeh_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01111000uuuuxxxxEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storewi0 */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01111000uuuuxxxxEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS2_storewi1 */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01111000uuuuxxxxEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SS1_storew_io */
HEXAGON_OPCODE ("Rx16 = add ( Ru16 , Rx16 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00111000uuuuxxxxEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_cmpeqi */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = #-1" , "00100IIIIIIIxxxxEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_setin1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = #u6" , "00100IIIIIIIxxxxEE1010iiiiiidddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_seti */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = add ( Rs16 , #-1 )" , "00100IIIIIIIxxxxEE110011ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_dec */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = add ( Rs16 , #1 )" , "00100IIIIIIIxxxxEE110001ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_inc */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = add ( Sp , #u6:2 )" , "00100IIIIIIIxxxxEE1011iiiiiidddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_addsp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = and ( Rs16 , #1 )" , "00100IIIIIIIxxxxEE110010ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_and1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = and ( Rs16 , #255 )" , "00100IIIIIIIxxxxEE110111ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_zxtb */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01000IIIIIIIxxxxEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_loadrb_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01000IIIIIIIxxxxEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_loadrh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01000IIIIIIIxxxxEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL1_loadrub_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01000IIIIIIIxxxxEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_loadruh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01000IIIIIIIxxxxEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL1_loadri_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01000IIIIIIIxxxxEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_loadri_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( #0 , #u2 )" , "00100IIIIIIIxxxxEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combine0i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00100IIIIIIIxxxxEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combinezr */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( #1 , #u2 )" , "00100IIIIIIIxxxxEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combine1i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( #2 , #u2 )" , "00100IIIIIIIxxxxEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combine2i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( #3 , #u2 )" , "00100IIIIIIIxxxxEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combine3i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00100IIIIIIIxxxxEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_combinerz */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01000IIIIIIIxxxxEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_loadrd_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; allocframe ( #u5:3 )" , "01100IIIIIIIxxxxEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_allocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; if ( ! p0 ) Rd16 = #0" , "00100IIIIIIIxxxxEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_clrf */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; if ( ! p0 .new ) Rd16 = #0" , "00100IIIIIIIxxxxEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_clrfnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; if ( p0 ) Rd16 = #0" , "00100IIIIIIIxxxxEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_clrt */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; if ( p0 .new ) Rd16 = #0" , "00100IIIIIIIxxxxEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_clrtnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01100IIIIIIIxxxxEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storebi0 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01100IIIIIIIxxxxEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storebi1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01100IIIIIIIxxxxEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS1_storeb_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01100IIIIIIIxxxxEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_stored_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01100IIIIIIIxxxxEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storeh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01100IIIIIIIxxxxEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storewi0 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01100IIIIIIIxxxxEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storewi1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01100IIIIIIIxxxxEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS1_storew_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01100IIIIIIIxxxxEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SS2_storew_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #S7 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00100IIIIIIIxxxxEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_cmpeqi */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; Rd16 = Rs16" , "00100iiiiiiixxxxEE110000ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_tfr */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; Rd16 = sxtb ( Rs16 )" , "00100iiiiiiixxxxEE110101ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_sxtb */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; Rd16 = sxth ( Rs16 )" , "00100iiiiiiixxxxEE110100ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_sxth */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; Rd16 = zxth ( Rs16 )" , "00100iiiiiiixxxxEE110110ssssdddd"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_zxth */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; dealloc_return" , "01000iiiiiiixxxxEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addi_SL2_return */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; deallocframe" , "01000iiiiiiixxxxEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_deallocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( ! p0 ) dealloc_return" , "01000iiiiiiixxxxEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addi_SL2_return_f */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( ! p0 ) jumpr Lr" , "01000iiiiiiixxxxEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01000iiiiiiixxxxEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addi_SL2_return_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01000iiiiiiixxxxEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( p0 ) dealloc_return" , "01000iiiiiiixxxxEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addi_SL2_return_t */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( p0 ) jumpr Lr" , "01000iiiiiiixxxxEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( p0 .new ) dealloc_return:nt" , "01000iiiiiiixxxxEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addi_SL2_return_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; if ( p0 .new ) jumpr:nt Lr" , "01000iiiiiiixxxxEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , #s7 ) ; jumpr Lr"   , "01000iiiiiiixxxxEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SL2_jumpr31 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rd16 = #-1" , "00111000ssssxxxxEE11101--0--dddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_setin1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01011000ssssxxxxEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_loadri_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rdd8 = combine ( #0 , #u2 )" , "00111000ssssxxxxEE1111-0-ii00ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combine0i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rdd8 = combine ( #1 , #u2 )" , "00111000ssssxxxxEE1111-0-ii01ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combine1i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rdd8 = combine ( #2 , #u2 )" , "00111000ssssxxxxEE1111-0-ii10ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combine2i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rdd8 = combine ( #3 , #u2 )" , "00111000ssssxxxxEE1111-0-ii11ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combine3i */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01011000ssssxxxxEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_loadrd_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; allocframe ( #u5:3 )" , "01111000ssssxxxxEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_allocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; dealloc_return" , "01011000ssssxxxxEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_SL2_return */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; deallocframe" , "01011000ssssxxxxEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_deallocframe */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 ) Rd16 = #0" , "00111000ssssxxxxEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_clrf */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 ) dealloc_return" , "01011000ssssxxxxEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_SL2_return_f */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 ) jumpr Lr" , "01011000ssssxxxxEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_jumpr31_f */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 .new ) Rd16 = #0" , "00111000ssssxxxxEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_clrfnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01011000ssssxxxxEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_SL2_return_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01011000ssssxxxxEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 ) Rd16 = #0" , "00111000ssssxxxxEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_clrt */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 ) dealloc_return" , "01011000ssssxxxxEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_SL2_return_t */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 ) jumpr Lr" , "01011000ssssxxxxEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_jumpr31_t */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 .new ) Rd16 = #0" , "00111000ssssxxxxEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_clrtnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 .new ) dealloc_return:nt" , "01011000ssssxxxxEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_addrx_SL2_return_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; if ( p0 .new ) jumpr:nt Lr" , "01011000ssssxxxxEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; jumpr Lr"  , "01011000ssssxxxxEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_jumpr31 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01111000ssssxxxxEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_stored_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Rs16 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01111000ssssxxxxEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storew_sp */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01011000uuuuxxxxEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_loadrb_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01011000uuuuxxxxEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_loadrh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01011000uuuuxxxxEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL1_loadrub_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01011000uuuuxxxxEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL2_loadruh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01011000uuuuxxxxEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SL1_loadri_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00111000uuuuxxxxEE1111-1ssss0ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combinezr */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00111000uuuuxxxxEE1111-1ssss1ddd"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_combinerz */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01111000uuuuxxxxEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storebi0 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01111000uuuuxxxxEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storebi1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01111000uuuuxxxxEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS1_storeb_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01111000uuuuxxxxEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storeh_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01111000uuuuxxxxEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storewi0 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01111000uuuuxxxxEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS2_storewi1 */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01111000uuuuxxxxEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SS1_storew_io */
HEXAGON_OPCODE ("Rx16 = add ( Rx16 , Ru16 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00111000uuuuxxxxEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_cmpeqi */
HEXAGON_OPCODE ("Rx32 &= and ( Rs32 , Rt32 )"            , "11101111010sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M4_and_and */
HEXAGON_OPCODE ("Rx32 &= and ( Rs32 , ~ Rt32 )"          , "11101111001sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M4_and_andn */
HEXAGON_OPCODE ("Rx32 &= asl ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_r_and */
HEXAGON_OPCODE ("Rx32 &= asl ( Rs32 , Rt32 )"            , "1100 1100  01-sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_r_and */
HEXAGON_OPCODE ("Rx32 &= asr ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 000xxxxx"       , 0xc, 0, 0) /* S2_asr_i_r_and */
HEXAGON_OPCODE ("Rx32 &= asr ( Rs32 , Rt32 )"            , "1100 1100  01-sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_r_and */
HEXAGON_OPCODE ("Rx32 &= lsl ( Rs32 , Rt32 )"            , "1100 1100  01-sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_r_and */
HEXAGON_OPCODE ("Rx32 &= lsr ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_r_and */
HEXAGON_OPCODE ("Rx32 &= lsr ( Rs32 , Rt32 )"            , "1100 1100  01-sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_r_and */
HEXAGON_OPCODE ("Rx32 &= or ( Rs32 , Rt32 )"             , "11101111010sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M4_and_or */
HEXAGON_OPCODE ("Rx32 &= xor ( Rs32 , Rt32 )"            , "11101111010sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M4_and_xor */
HEXAGON_OPCODE ("Rx32 += add ( Rs32 , #s8 )"             , "111000100--sssss  PP0iiiii iiixxxxx"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M2_accii */
HEXAGON_OPCODE ("Rx32 += add ( Rs32 , Rt32 )"            , "11101111000sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_acci */
HEXAGON_OPCODE ("Rx32 += asl ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 110xxxxx"       , 0xc, 0, 0) /* S2_asl_i_r_acc */
HEXAGON_OPCODE ("Rx32 += asl ( Rs32 , Rt32 )"            , "1100 1100  11-sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_r_acc */
HEXAGON_OPCODE ("Rx32 += asr ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 100xxxxx"       , 0xc, 0, 0) /* S2_asr_i_r_acc */
HEXAGON_OPCODE ("Rx32 += asr ( Rs32 , Rt32 )"            , "1100 1100  11-sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_r_acc */
HEXAGON_OPCODE ("Rx32 += lsl ( Rs32 , Rt32 )"            , "1100 1100  11-sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_r_acc */
HEXAGON_OPCODE ("Rx32 += lsr ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 101xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_r_acc */
HEXAGON_OPCODE ("Rx32 += lsr ( Rs32 , Rt32 )"            , "1100 1100  11-sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_r_acc */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.h ) :<<1 :sat" , "11101110100sssss  PP-ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_hh_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.h ) :<<1"   , "11101110100sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_hh_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.h ) :sat"   , "11101110000sssss  PP-ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_hh_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.h )"        , "11101110000sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_hh_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.l ) :<<1 :sat" , "11101110100sssss  PP-ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_hl_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.l ) :<<1"   , "11101110100sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_hl_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.l ) :sat"   , "11101110000sssss  PP-ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_hl_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.h , Rt32.l )"        , "11101110000sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_hl_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.h ) :<<1 :sat" , "11101110100sssss  PP-ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_lh_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.h ) :<<1"   , "11101110100sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_lh_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.h ) :sat"   , "11101110000sssss  PP-ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_lh_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.h )"        , "11101110000sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_lh_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.l ) :<<1 :sat" , "11101110100sssss  PP-ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_ll_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.l ) :<<1"   , "11101110100sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_ll_s1 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.l ) :sat"   , "11101110000sssss  PP-ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_acc_sat_ll_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32.l , Rt32.l )"        , "11101110000sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpy_acc_ll_s0 */
HEXAGON_OPCODE ("Rx32 += mpy ( Rs32 , Rt32 ) :<<1 :sat"  , "11101111011sssss  PP0ttttt 000xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_mac_up_s1_sat */
HEXAGON_OPCODE ("Rx32 += mpyi ( Rs32 , #u8 )"            , "111000010--sssss  PP0iiiii iiixxxxx"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M2_macsip */
HEXAGON_OPCODE ("Rx32 += mpyi ( Rs32 , Rt32 )"           , "11101111000sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_maci */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.h , Rt32.h ) :<<1"  , "11101110110sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_hh_s1 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.h , Rt32.h )"       , "11101110010sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_hh_s0 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.h , Rt32.l ) :<<1"  , "11101110110sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_hl_s1 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.h , Rt32.l )"       , "11101110010sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_hl_s0 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.l , Rt32.h ) :<<1"  , "11101110110sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_lh_s1 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.l , Rt32.h )"       , "11101110010sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_lh_s0 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.l , Rt32.l ) :<<1"  , "11101110110sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_ll_s1 */
HEXAGON_OPCODE ("Rx32 += mpyu ( Rs32.l , Rt32.l )"       , "11101110010sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyu_acc_ll_s0 */
HEXAGON_OPCODE ("Rx32 += sfmpy ( Rs32 , Rt32 ) :lib"     , "11101111000sssss  PP0ttttt 110xxxxx"        , 0xc, 0, 0|A_CONDEXEC|A_XFLOAT) /* F2_sffma_lib */
HEXAGON_OPCODE ("Rx32 += sfmpy ( Rs32 , Rt32 )"          , "11101111000sssss  PP0ttttt 100xxxxx"        , 0xc, 0, 0|A_XFLOAT) /* F2_sffma */
HEXAGON_OPCODE ("Rx32 += sfmpy ( Rs32 , Rt32 , Pu4 ) :scale" , "11101111011sssss  PP0ttttt 1uuxxxxx"        , 0xc, 0, 0|A_XFLOAT) /* F2_sffma_sc */
HEXAGON_OPCODE ("Rx32 += sub ( Rt32 , Rs32 )"            , "11101111000sssss  PP0ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_subacc */
HEXAGON_OPCODE ("Rx32 -= add ( Rs32 , #s8 )"             , "111000101--sssss  PP0iiiii iiixxxxx"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M2_naccii */
HEXAGON_OPCODE ("Rx32 -= add ( Rs32 , Rt32 )"            , "11101111100sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_nacci */
HEXAGON_OPCODE ("Rx32 -= asl ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_r_nac */
HEXAGON_OPCODE ("Rx32 -= asl ( Rs32 , Rt32 )"            , "1100 1100  10-sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_r_nac */
HEXAGON_OPCODE ("Rx32 -= asr ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 000xxxxx"       , 0xc, 0, 0) /* S2_asr_i_r_nac */
HEXAGON_OPCODE ("Rx32 -= asr ( Rs32 , Rt32 )"            , "1100 1100  10-sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_r_nac */
HEXAGON_OPCODE ("Rx32 -= lsl ( Rs32 , Rt32 )"            , "1100 1100  10-sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_r_nac */
HEXAGON_OPCODE ("Rx32 -= lsr ( Rs32 , #u5 )"             , "1000 1110 00-sssss PP0iiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_r_nac */
HEXAGON_OPCODE ("Rx32 -= lsr ( Rs32 , Rt32 )"            , "1100 1100  10-sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_r_nac */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.h ) :<<1 :sat" , "11101110101sssss  PP-ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_hh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.h ) :<<1"   , "11101110101sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_hh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.h ) :sat"   , "11101110001sssss  PP-ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_hh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.h )"        , "11101110001sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_hh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.l ) :<<1 :sat" , "11101110101sssss  PP-ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_hl_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.l ) :<<1"   , "11101110101sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_hl_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.l ) :sat"   , "11101110001sssss  PP-ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_hl_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.h , Rt32.l )"        , "11101110001sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_hl_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.h ) :<<1 :sat" , "11101110101sssss  PP-ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_lh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.h ) :<<1"   , "11101110101sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_lh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.h ) :sat"   , "11101110001sssss  PP-ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_lh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.h )"        , "11101110001sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_lh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.l ) :<<1 :sat" , "11101110101sssss  PP-ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_ll_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.l ) :<<1"   , "11101110101sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_ll_s1 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.l ) :sat"   , "11101110001sssss  PP-ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mpy_nac_sat_ll_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32.l , Rt32.l )"        , "11101110001sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpy_nac_ll_s0 */
HEXAGON_OPCODE ("Rx32 -= mpy ( Rs32 , Rt32 ) :<<1 :sat"  , "11101111011sssss  PP0ttttt 001xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M4_nac_up_s1_sat */
HEXAGON_OPCODE ("Rx32 -= mpyi ( Rs32 , #u8 )"            , "111000011--sssss  PP0iiiii iiixxxxx"        , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* M2_macsin */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.h , Rt32.h ) :<<1"  , "11101110111sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_hh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.h , Rt32.h )"       , "11101110011sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_hh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.h , Rt32.l ) :<<1"  , "11101110111sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_hl_s1 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.h , Rt32.l )"       , "11101110011sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_hl_s0 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.l , Rt32.h ) :<<1"  , "11101110111sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_lh_s1 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.l , Rt32.h )"       , "11101110011sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_lh_s0 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.l , Rt32.l ) :<<1"  , "11101110111sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_ll_s1 */
HEXAGON_OPCODE ("Rx32 -= mpyu ( Rs32.l , Rt32.l )"       , "11101110011sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyu_nac_ll_s0 */
HEXAGON_OPCODE ("Rx32 -= sfmpy ( Rs32 , Rt32 ) :lib"     , "11101111000sssss  PP0ttttt 111xxxxx"        , 0xc, 0, 0|A_CONDEXEC|A_XFLOAT) /* F2_sffms_lib */
HEXAGON_OPCODE ("Rx32 -= sfmpy ( Rs32 , Rt32 )"          , "11101111000sssss  PP0ttttt 101xxxxx"        , 0xc, 0, 0|A_XFLOAT) /* F2_sffms */
HEXAGON_OPCODE ("Rx32 = add ( #u8 , asl ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii0i10-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_addi_asl_ri */
HEXAGON_OPCODE ("Rx32 = add ( #u8 , lsr ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii1i10-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_addi_lsr_ri */
HEXAGON_OPCODE ("Rx32 = and ( #u8 , asl ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii0i00-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_andi_asl_ri */
HEXAGON_OPCODE ("Rx32 = and ( #u8 , lsr ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii1i00-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_andi_lsr_ri */
HEXAGON_OPCODE ("Rx32 = insert ( Rs32 , #u5 , #U5 )"     , "1000 1111 0IIsssss PP0iiiii IIIxxxxx"       , 0xc, 0, 0) /* S2_insert */
HEXAGON_OPCODE ("Rx32 = insert ( Rs32 , Rtt32 )"         , "1100 1000  ---sssss  PP-ttttt ---xxxxx"     , 0xc, 0, 0) /* S2_insert_rp */
HEXAGON_OPCODE ("Rx32 = or ( #u8 , asl ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii0i01-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_ori_asl_ri */
HEXAGON_OPCODE ("Rx32 = or ( #u8 , lsr ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii1i01-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_ori_lsr_ri */
HEXAGON_OPCODE ("Rx32 = or ( Ru32 , and ( Rx32 , #s10 ) )" , "1101 1010   01i xxxxx PPiiiiii iiiuuuuu"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_or_andix */
HEXAGON_OPCODE ("Rx32 = sub ( #u8 , asl ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii0i11-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_subi_asl_ri */
HEXAGON_OPCODE ("Rx32 = sub ( #u8 , lsr ( Rx32 , #U5 ) )" , "1101 1110 iiixxxxx PPiIIIII iii1i11-"       , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_subi_lsr_ri */
HEXAGON_OPCODE ("Rx32 = tableidxb ( Rs32 , #u4 , #S6 ) :raw" , "1000 0111 00isssss PPIIIIII iiixxxxx"       , 0xc, 0, 0) /* S2_tableidxb */
HEXAGON_MAPPING ("Rx32 = tableidxb ( Rs32 , #u4 , #U5 )"  , "0000IIIIIxxxxxsssssiiii000000000"           , HEXAGON_MAP_FNAME(S2_tableidxb_goodsyntax)) /* mapped to Rx32=tableidxb(Rs32,#u4,#U5):raw */
HEXAGON_OPCODE ("Rx32 = tableidxd ( Rs32 , #u4 , #S6 ) :raw" , "1000 0111 11isssss PPIIIIII iiixxxxx"       , 0xc, 0, 0) /* S2_tableidxd */
HEXAGON_MAPPING ("Rx32 = tableidxd ( Rs32 , #u4 , #U5 )"  , "0000IIIIIxxxxxsssssiiii000000000"           , HEXAGON_MAP_FNAME(S2_tableidxd_goodsyntax)) /* mapped to Rx32=tableidxd(Rs32,#u4,#U5-3):raw */
HEXAGON_OPCODE ("Rx32 = tableidxh ( Rs32 , #u4 , #S6 ) :raw" , "1000 0111 01isssss PPIIIIII iiixxxxx"       , 0xc, 0, 0) /* S2_tableidxh */
HEXAGON_MAPPING ("Rx32 = tableidxh ( Rs32 , #u4 , #U5 )"  , "0000IIIIIxxxxxsssssiiii000000000"           , HEXAGON_MAP_FNAME(S2_tableidxh_goodsyntax)) /* mapped to Rx32=tableidxh(Rs32,#u4,#U5-1):raw */
HEXAGON_OPCODE ("Rx32 = tableidxw ( Rs32 , #u4 , #S6 ) :raw" , "1000 0111 10isssss PPIIIIII iiixxxxx"       , 0xc, 0, 0) /* S2_tableidxw */
HEXAGON_MAPPING ("Rx32 = tableidxw ( Rs32 , #u4 , #U5 )"  , "0000IIIIIxxxxxsssssiiii000000000"           , HEXAGON_MAP_FNAME(S2_tableidxw_goodsyntax)) /* mapped to Rx32=tableidxw(Rs32,#u4,#U5-2):raw */
HEXAGON_OPCODE ("Rx32 ^= and ( Rs32 , Rt32 )"            , "11101111110sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M4_xor_and */
HEXAGON_OPCODE ("Rx32 ^= and ( Rs32 , ~ Rt32 )"          , "11101111001sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M4_xor_andn */
HEXAGON_OPCODE ("Rx32 ^= asl ( Rs32 , #u5 )"             , "1000 1110 10-sssss PP0iiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_r_xacc */
HEXAGON_OPCODE ("Rx32 ^= lsr ( Rs32 , #u5 )"             , "1000 1110 10-sssss PP0iiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_r_xacc */
HEXAGON_OPCODE ("Rx32 ^= or ( Rs32 , Rt32 )"             , "11101111110sssss  PP0ttttt 011xxxxx"        , 0xc, 0, 0) /* M4_xor_or */
HEXAGON_OPCODE ("Rx32 ^= xor ( Rs32 , Rt32 )"            , "11101111100sssss  PP0ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_xor_xacc */
HEXAGON_OPCODE ("Rx32 |= and ( Rs32 , #s10 )"            , "1101 1010   00i sssss PPiiiiii iiixxxxx"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_or_andi */
HEXAGON_OPCODE ("Rx32 |= and ( Rs32 , Rt32 )"            , "11101111010sssss  PP0ttttt 011xxxxx"        , 0xc, 0, 0) /* M4_or_and */
HEXAGON_OPCODE ("Rx32 |= and ( Rs32 , ~ Rt32 )"          , "11101111001sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M4_or_andn */
HEXAGON_OPCODE ("Rx32 |= asl ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 110xxxxx"       , 0xc, 0, 0) /* S2_asl_i_r_or */
HEXAGON_OPCODE ("Rx32 |= asl ( Rs32 , Rt32 )"            , "1100 1100  00-sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_r_or */
HEXAGON_OPCODE ("Rx32 |= asr ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 100xxxxx"       , 0xc, 0, 0) /* S2_asr_i_r_or */
HEXAGON_OPCODE ("Rx32 |= asr ( Rs32 , Rt32 )"            , "1100 1100  00-sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_r_or */
HEXAGON_OPCODE ("Rx32 |= lsl ( Rs32 , Rt32 )"            , "1100 1100  00-sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_r_or */
HEXAGON_OPCODE ("Rx32 |= lsr ( Rs32 , #u5 )"             , "1000 1110 01-sssss PP0iiiii 101xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_r_or */
HEXAGON_OPCODE ("Rx32 |= lsr ( Rs32 , Rt32 )"            , "1100 1100  00-sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_r_or */
HEXAGON_OPCODE ("Rx32 |= or ( Rs32 , #s10 )"             , "1101 1010   10i sssss PPiiiiii iiixxxxx"    , 0xc, 0, 0|A_EXTENDABLE_LOWERCASE) /* S4_or_ori */
HEXAGON_OPCODE ("Rx32 |= or ( Rs32 , Rt32 )"             , "11101111110sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M4_or_or */
HEXAGON_OPCODE ("Rx32 |= xor ( Rs32 , Rt32 )"            , "11101111110sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M4_or_xor */
HEXAGON_OPCODE ("Rxx32 &= asl ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_p_and */
HEXAGON_OPCODE ("Rxx32 &= asl ( Rss32 , Rt32 )"          , "1100 1011  010sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_p_and */
HEXAGON_OPCODE ("Rxx32 &= asr ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 000xxxxx"       , 0xc, 0, 0) /* S2_asr_i_p_and */
HEXAGON_OPCODE ("Rxx32 &= asr ( Rss32 , Rt32 )"          , "1100 1011  010sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_p_and */
HEXAGON_OPCODE ("Rxx32 &= lsl ( Rss32 , Rt32 )"          , "1100 1011  010sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_p_and */
HEXAGON_OPCODE ("Rxx32 &= lsr ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_p_and */
HEXAGON_OPCODE ("Rxx32 &= lsr ( Rss32 , Rt32 )"          , "1100 1011  010sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_p_and */
HEXAGON_OPCODE ("Rxx32 += asl ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 110xxxxx"       , 0xc, 0, 0) /* S2_asl_i_p_acc */
HEXAGON_OPCODE ("Rxx32 += asl ( Rss32 , Rt32 )"          , "1100 1011  110sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_p_acc */
HEXAGON_OPCODE ("Rxx32 += asr ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 100xxxxx"       , 0xc, 0, 0) /* S2_asr_i_p_acc */
HEXAGON_OPCODE ("Rxx32 += asr ( Rss32 , Rt32 )"          , "1100 1011  110sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_p_acc */
HEXAGON_OPCODE ("Rxx32 += cmpy ( Rs32 , Rt32 ) :<<1 :sat" , "11100111100sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmacs_s1 */
HEXAGON_OPCODE ("Rxx32 += cmpy ( Rs32 , Rt32 ) :sat"     , "11100111000sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmacs_s0 */
HEXAGON_OPCODE ("Rxx32 += cmpy ( Rs32 , Rt32 * ) :<<1 :sat" , "11100111110sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmacsc_s1 */
HEXAGON_OPCODE ("Rxx32 += cmpy ( Rs32 , Rt32 * ) :sat"   , "11100111010sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cmacsc_s0 */
HEXAGON_OPCODE ("Rxx32 += cmpyi ( Rs32 , Rt32 )"         , "11100111000sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_cmaci_s0 */
HEXAGON_OPCODE ("Rxx32 += cmpyr ( Rs32 , Rt32 )"         , "11100111000sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_cmacr_s0 */
HEXAGON_OPCODE ("Rxx32 += lsl ( Rss32 , Rt32 )"          , "1100 1011  110sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_p_acc */
HEXAGON_OPCODE ("Rxx32 += lsr ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 101xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_p_acc */
HEXAGON_OPCODE ("Rxx32 += lsr ( Rss32 , Rt32 )"          , "1100 1011  110sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_p_acc */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.h , Rt32.h ) :<<1"  , "11100110100sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_hh_s1 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.h , Rt32.h )"       , "11100110000sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_hh_s0 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.h , Rt32.l ) :<<1"  , "11100110100sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_hl_s1 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.h , Rt32.l )"       , "11100110000sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_hl_s0 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.l , Rt32.h ) :<<1"  , "11100110100sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_lh_s1 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.l , Rt32.h )"       , "11100110000sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_lh_s0 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.l , Rt32.l ) :<<1"  , "11100110100sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_ll_s1 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32.l , Rt32.l )"       , "11100110000sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyd_acc_ll_s0 */
HEXAGON_OPCODE ("Rxx32 += mpy ( Rs32 , Rt32 )"           , "11100111000sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_dpmpyss_acc_s0 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.h , Rt32.h ) :<<1" , "11100110110sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_hh_s1 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.h , Rt32.h )"      , "11100110010sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_hh_s0 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.h , Rt32.l ) :<<1" , "11100110110sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_hl_s1 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.h , Rt32.l )"      , "11100110010sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_hl_s0 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.l , Rt32.h ) :<<1" , "11100110110sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_lh_s1 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.l , Rt32.h )"      , "11100110010sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_lh_s0 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.l , Rt32.l ) :<<1" , "11100110110sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_ll_s1 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32.l , Rt32.l )"      , "11100110010sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyud_acc_ll_s0 */
HEXAGON_OPCODE ("Rxx32 += mpyu ( Rs32 , Rt32 )"          , "11100111010sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_dpmpyuu_acc_s0 */
HEXAGON_OPCODE ("Rxx32 += vcmpyi ( Rss32 , Rtt32 ) :sat" , "11101010010sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmac_s0_sat_i */
HEXAGON_OPCODE ("Rxx32 += vcmpyr ( Rss32 , Rtt32 ) :sat" , "11101010001sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vcmac_s0_sat_r */
HEXAGON_OPCODE ("Rxx32 += vdmpy ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010100sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmacs_s1 */
HEXAGON_OPCODE ("Rxx32 += vdmpy ( Rss32 , Rtt32 ) :sat"  , "11101010000sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vdmacs_s0 */
HEXAGON_OPCODE ("Rxx32 += vdmpybsu ( Rss32 , Rtt32 ) :sat" , "11101010001sssss  PP0ttttt 001xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M5_vdmacbsu */
HEXAGON_OPCODE ("Rxx32 += vmpybsu ( Rs32 , Rt32 )"       , "11100111110sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M5_vmacbsu */
HEXAGON_OPCODE ("Rxx32 += vmpybu ( Rs32 , Rt32 )"        , "11100111100sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M5_vmacbuu */
HEXAGON_OPCODE ("Rxx32 += vmpyeh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010100sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2es_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpyeh ( Rss32 , Rtt32 ) :sat" , "11101010000sssss  PP0ttttt 110xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2es_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpyeh ( Rss32 , Rtt32 )"      , "11101010001sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_vmac2es */
HEXAGON_OPCODE ("Rxx32 += vmpyh ( Rs32 , Rt32 ) :<<1 :sat" , "11100111100sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2s_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpyh ( Rs32 , Rt32 ) :sat"    , "11100111000sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2s_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpyh ( Rs32 , Rt32 )"         , "11100111001sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_vmac2 */
HEXAGON_OPCODE ("Rxx32 += vmpyhsu ( Rs32 , Rt32 ) :<<1 :sat" , "11100111111sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2su_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpyhsu ( Rs32 , Rt32 ) :sat"  , "11100111011sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vmac2su_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpyweh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101010101sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacls_rs1 */
HEXAGON_OPCODE ("Rxx32 += vmpyweh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010100sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacls_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpyweh ( Rss32 , Rtt32 ) :rnd :sat" , "11101010001sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacls_rs0 */
HEXAGON_OPCODE ("Rxx32 += vmpyweh ( Rss32 , Rtt32 ) :sat" , "11101010000sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacls_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpyweuh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101010111sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmaculs_rs1 */
HEXAGON_OPCODE ("Rxx32 += vmpyweuh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010110sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmaculs_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpyweuh ( Rss32 , Rtt32 ) :rnd :sat" , "11101010011sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmaculs_rs0 */
HEXAGON_OPCODE ("Rxx32 += vmpyweuh ( Rss32 , Rtt32 ) :sat" , "11101010010sssss  PP0ttttt 101xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmaculs_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpywoh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101010101sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmachs_rs1 */
HEXAGON_OPCODE ("Rxx32 += vmpywoh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010100sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmachs_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpywoh ( Rss32 , Rtt32 ) :rnd :sat" , "11101010001sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmachs_rs0 */
HEXAGON_OPCODE ("Rxx32 += vmpywoh ( Rss32 , Rtt32 ) :sat" , "11101010000sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmachs_s0 */
HEXAGON_OPCODE ("Rxx32 += vmpywouh ( Rss32 , Rtt32 ) :<<1 :rnd :sat" , "11101010111sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacuhs_rs1 */
HEXAGON_OPCODE ("Rxx32 += vmpywouh ( Rss32 , Rtt32 ) :<<1 :sat" , "11101010110sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacuhs_s1 */
HEXAGON_OPCODE ("Rxx32 += vmpywouh ( Rss32 , Rtt32 ) :rnd :sat" , "11101010011sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacuhs_rs0 */
HEXAGON_OPCODE ("Rxx32 += vmpywouh ( Rss32 , Rtt32 ) :sat" , "11101010010sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_mmacuhs_s0 */
HEXAGON_OPCODE ("Rxx32 += vraddub ( Rss32 , Rtt32 )"     , "11101010010sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* A2_vraddub_acc */
HEXAGON_OPCODE ("Rxx32 += vrcmpyi ( Rss32 , Rtt32 )"     , "11101010000sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_vrcmaci_s0 */
HEXAGON_OPCODE ("Rxx32 += vrcmpyi ( Rss32 , Rtt32 * )"   , "11101010010sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_vrcmaci_s0c */
HEXAGON_OPCODE ("Rxx32 += vrcmpyr ( Rss32 , Rtt32 )"     , "11101010000sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_vrcmacr_s0 */
HEXAGON_OPCODE ("Rxx32 += vrcmpyr ( Rss32 , Rtt32 * )"   , "11101010011sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_vrcmacr_s0c */
HEXAGON_MAPPING ("Rxx32 += vrcmpys ( Rss32 , Rt32 ) :<<1 :sat" , "0000xxxxxsssssttttt0000000000000"           , HEXAGON_MAP_FNAME(M2_vrcmpys_acc_s1)) /* mapped to Rxx32+=vrcmpys(Rss32,Rtt32):<<1:sat:raw:hi or Rxx32+=vrcmpys(Rss32,Rtt32):<<1:sat:raw:lo */
HEXAGON_OPCODE ("Rxx32 += vrcmpys ( Rss32 , Rtt32 ) :<<1 :sat :raw :hi" , "11101010101sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_acc_s1_h */
HEXAGON_OPCODE ("Rxx32 += vrcmpys ( Rss32 , Rtt32 ) :<<1 :sat :raw :lo" , "11101010111sssss  PP0ttttt 100xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_vrcmpys_acc_s1_l */
HEXAGON_OPCODE ("Rxx32 += vrcnegh ( Rss32 , Rt32 )"      , "1100 1011  001sssss  PP1ttttt 111xxxxx"     , 0xc, 0, 0) /* S2_vrcnegh */
HEXAGON_OPCODE ("Rxx32 += vrcrotate ( Rss32 , Rt32 , #u2 )" , "1100 1011  101sssss  PPittttt --ixxxxx"     , 0xc, 0, 0) /* S4_vrcrotate_acc */
HEXAGON_OPCODE ("Rxx32 += vrmpybsu ( Rss32 , Rtt32 )"    , "11101010110sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M5_vrmacbsu */
HEXAGON_OPCODE ("Rxx32 += vrmpybu ( Rss32 , Rtt32 )"     , "11101010100sssss  PP0ttttt 001xxxxx"        , 0xc, 0, 0) /* M5_vrmacbuu */
HEXAGON_OPCODE ("Rxx32 += vrmpyh ( Rss32 , Rtt32 )"      , "11101010000sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_vrmac_s0 */
HEXAGON_OPCODE ("Rxx32 += vrmpyweh ( Rss32 , Rtt32 ) :<<1" , "11101010101sssss  PP0ttttt 110xxxxx"        , 0xc, 0, 0) /* M4_vrmpyeh_acc_s1 */
HEXAGON_OPCODE ("Rxx32 += vrmpyweh ( Rss32 , Rtt32 )"    , "11101010001sssss  PP0ttttt 110xxxxx"        , 0xc, 0, 0) /* M4_vrmpyeh_acc_s0 */
HEXAGON_OPCODE ("Rxx32 += vrmpywoh ( Rss32 , Rtt32 ) :<<1" , "11101010111sssss  PP0ttttt 110xxxxx"        , 0xc, 0, 0) /* M4_vrmpyoh_acc_s1 */
HEXAGON_OPCODE ("Rxx32 += vrmpywoh ( Rss32 , Rtt32 )"    , "11101010011sssss  PP0ttttt 110xxxxx"        , 0xc, 0, 0) /* M4_vrmpyoh_acc_s0 */
HEXAGON_OPCODE ("Rxx32 += vrsadub ( Rss32 , Rtt32 )"     , "11101010010sssss  PP0ttttt 010xxxxx"        , 0xc, 0, 0) /* A2_vrsadub_acc */
HEXAGON_OPCODE ("Rxx32 -= asl ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_p_nac */
HEXAGON_OPCODE ("Rxx32 -= asl ( Rss32 , Rt32 )"          , "1100 1011  100sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_p_nac */
HEXAGON_OPCODE ("Rxx32 -= asr ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 000xxxxx"       , 0xc, 0, 0) /* S2_asr_i_p_nac */
HEXAGON_OPCODE ("Rxx32 -= asr ( Rss32 , Rt32 )"          , "1100 1011  100sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_p_nac */
HEXAGON_OPCODE ("Rxx32 -= cmpy ( Rs32 , Rt32 ) :<<1 :sat" , "11100111100sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cnacs_s1 */
HEXAGON_OPCODE ("Rxx32 -= cmpy ( Rs32 , Rt32 ) :sat"     , "11100111000sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cnacs_s0 */
HEXAGON_OPCODE ("Rxx32 -= cmpy ( Rs32 , Rt32 * ) :<<1 :sat" , "11100111110sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cnacsc_s1 */
HEXAGON_OPCODE ("Rxx32 -= cmpy ( Rs32 , Rt32 * ) :sat"   , "11100111010sssss  PP0ttttt 111xxxxx"        , 0xc, 0|IMPLICIT_SR_OVF, 0) /* M2_cnacsc_s0 */
HEXAGON_OPCODE ("Rxx32 -= lsl ( Rss32 , Rt32 )"          , "1100 1011  100sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_p_nac */
HEXAGON_OPCODE ("Rxx32 -= lsr ( Rss32 , #u6 )"           , "1000 0010 00-sssss PPiiiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_p_nac */
HEXAGON_OPCODE ("Rxx32 -= lsr ( Rss32 , Rt32 )"          , "1100 1011  100sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_p_nac */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.h , Rt32.h ) :<<1"  , "11100110101sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_hh_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.h , Rt32.h )"       , "11100110001sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_hh_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.h , Rt32.l ) :<<1"  , "11100110101sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_hl_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.h , Rt32.l )"       , "11100110001sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_hl_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.l , Rt32.h ) :<<1"  , "11100110101sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_lh_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.l , Rt32.h )"       , "11100110001sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_lh_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.l , Rt32.l ) :<<1"  , "11100110101sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_ll_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32.l , Rt32.l )"       , "11100110001sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyd_nac_ll_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpy ( Rs32 , Rt32 )"           , "11100111001sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_dpmpyss_nac_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.h , Rt32.h ) :<<1" , "11100110111sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_hh_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.h , Rt32.h )"      , "11100110011sssss  PP-ttttt 011xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_hh_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.h , Rt32.l ) :<<1" , "11100110111sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_hl_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.h , Rt32.l )"      , "11100110011sssss  PP-ttttt 010xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_hl_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.l , Rt32.h ) :<<1" , "11100110111sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_lh_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.l , Rt32.h )"      , "11100110011sssss  PP-ttttt 001xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_lh_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.l , Rt32.l ) :<<1" , "11100110111sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_ll_s1 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32.l , Rt32.l )"      , "11100110011sssss  PP-ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_mpyud_nac_ll_s0 */
HEXAGON_OPCODE ("Rxx32 -= mpyu ( Rs32 , Rt32 )"          , "11100111011sssss  PP0ttttt 000xxxxx"        , 0xc, 0, 0) /* M2_dpmpyuu_nac_s0 */
HEXAGON_OPCODE ("Rxx32 = insert ( Rss32 , #u6 , #U6 )"   , "1000 0011 IIIsssss PPiiiiii IIIxxxxx"       , 0xc, 0, 0) /* S2_insertp */
HEXAGON_OPCODE ("Rxx32 = insert ( Rss32 , Rtt32 )"       , "1100 1010  0--sssss  PP0ttttt ---xxxxx"     , 0xc, 0, 0) /* S2_insertp_rp */
HEXAGON_OPCODE ("Rxx32 = userinsn ( Rss32 , Rtt32 , #u7 )" , "1100 1111 iiisssss PPittttt iiixxxxx"       , 0xc, 0, 0) /* S6_userinsn */
HEXAGON_OPCODE ("Rxx32 = vrmaxh ( Rss32 , Ru32 )"        , "1100 1011  001sssss  PP0xxxxx 001uuuuu"     , 0xc, 0, 0) /* A4_vrmaxh */
HEXAGON_OPCODE ("Rxx32 = vrmaxuh ( Rss32 , Ru32 )"       , "1100 1011  001sssss  PP1xxxxx 001uuuuu"     , 0xc, 0, 0) /* A4_vrmaxuh */
HEXAGON_OPCODE ("Rxx32 = vrmaxuw ( Rss32 , Ru32 )"       , "1100 1011  001sssss  PP1xxxxx 010uuuuu"     , 0xc, 0, 0) /* A4_vrmaxuw */
HEXAGON_OPCODE ("Rxx32 = vrmaxw ( Rss32 , Ru32 )"        , "1100 1011  001sssss  PP0xxxxx 010uuuuu"     , 0xc, 0, 0) /* A4_vrmaxw */
HEXAGON_OPCODE ("Rxx32 = vrminh ( Rss32 , Ru32 )"        , "1100 1011  001sssss  PP0xxxxx 101uuuuu"     , 0xc, 0, 0) /* A4_vrminh */
HEXAGON_OPCODE ("Rxx32 = vrminuh ( Rss32 , Ru32 )"       , "1100 1011  001sssss  PP1xxxxx 101uuuuu"     , 0xc, 0, 0) /* A4_vrminuh */
HEXAGON_OPCODE ("Rxx32 = vrminuw ( Rss32 , Ru32 )"       , "1100 1011  001sssss  PP1xxxxx 110uuuuu"     , 0xc, 0, 0) /* A4_vrminuw */
HEXAGON_OPCODE ("Rxx32 = vrminw ( Rss32 , Ru32 )"        , "1100 1011  001sssss  PP0xxxxx 110uuuuu"     , 0xc, 0, 0) /* A4_vrminw */
HEXAGON_OPCODE ("Rxx32 ^= asl ( Rss32 , #u6 )"           , "1000 0010 10-sssss PPiiiiii 010xxxxx"       , 0xc, 0, 0) /* S2_asl_i_p_xacc */
HEXAGON_OPCODE ("Rxx32 ^= asl ( Rss32 , Rt32 )"          , "1100 1011  011sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_p_xor */
HEXAGON_OPCODE ("Rxx32 ^= asr ( Rss32 , Rt32 )"          , "1100 1011  011sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_p_xor */
HEXAGON_OPCODE ("Rxx32 ^= lsl ( Rss32 , Rt32 )"          , "1100 1011  011sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_p_xor */
HEXAGON_OPCODE ("Rxx32 ^= lsr ( Rss32 , #u6 )"           , "1000 0010 10-sssss PPiiiiii 001xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_p_xacc */
HEXAGON_OPCODE ("Rxx32 ^= lsr ( Rss32 , Rt32 )"          , "1100 1011  011sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_p_xor */
HEXAGON_OPCODE ("Rxx32 ^= pmpyw ( Rs32 , Rt32 )"         , "11100111001sssss  PP0ttttt 111xxxxx"        , 0xc, 0, 0) /* M4_pmpyw_acc */
HEXAGON_OPCODE ("Rxx32 ^= vpmpyh ( Rs32 , Rt32 )"        , "11100111101sssss  PP0ttttt 111xxxxx"        , 0xc, 0, 0) /* M4_vpmpyh_acc */
HEXAGON_OPCODE ("Rxx32 ^= xor ( Rss32 , Rtt32 )"         , "1100 1010  1--sssss  PP0ttttt ---xxxxx"     , 0xc, 0, 0) /* M4_xor_xacc */
HEXAGON_OPCODE ("Rxx32 |= asl ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 110xxxxx"       , 0xc, 0, 0) /* S2_asl_i_p_or */
HEXAGON_OPCODE ("Rxx32 |= asl ( Rss32 , Rt32 )"          , "1100 1011  000sssss  PP-ttttt 10-xxxxx"     , 0xc, 0, 0) /* S2_asl_r_p_or */
HEXAGON_OPCODE ("Rxx32 |= asr ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 100xxxxx"       , 0xc, 0, 0) /* S2_asr_i_p_or */
HEXAGON_OPCODE ("Rxx32 |= asr ( Rss32 , Rt32 )"          , "1100 1011  000sssss  PP-ttttt 00-xxxxx"     , 0xc, 0, 0) /* S2_asr_r_p_or */
HEXAGON_OPCODE ("Rxx32 |= lsl ( Rss32 , Rt32 )"          , "1100 1011  000sssss  PP-ttttt 11-xxxxx"     , 0xc, 0, 0) /* S2_lsl_r_p_or */
HEXAGON_OPCODE ("Rxx32 |= lsr ( Rss32 , #u6 )"           , "1000 0010 01-sssss PPiiiiii 101xxxxx"       , 0xc, 0, 0) /* S2_lsr_i_p_or */
HEXAGON_OPCODE ("Rxx32 |= lsr ( Rss32 , Rt32 )"          , "1100 1011  000sssss  PP-ttttt 01-xxxxx"     , 0xc, 0, 0) /* S2_lsr_r_p_or */
HEXAGON_OPCODE ("Ry16 = add ( Ru16 , Ry16 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00111000uuuuyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_addrx_commuted */
HEXAGON_OPCODE ("Ry16 = add ( Ru16 , Ry16 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00111000uuuuyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_commuted_SA1_addrx */
HEXAGON_OPCODE ("Ry16 = add ( Ry16 , #S7 ) ; Rx16 = add ( Rx16 , #s7 )" , "00100IIIIIIIyyyyEE100iiiiiiixxxx"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_UPPERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_addi */
HEXAGON_OPCODE ("Ry16 = add ( Ry16 , #s7 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00100iiiiiiiyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_addrx_commuted */
HEXAGON_OPCODE ("Ry16 = add ( Ry16 , #s7 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00100iiiiiiiyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* X2_AUTOJOIN_SA1_addi_SA1_addrx */
HEXAGON_OPCODE ("Ry16 = add ( Ry16 , Ru16 ) ; Rx16 = add ( Rs16 , Rx16 )" , "00111000uuuuyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_addrx_commuted */
HEXAGON_OPCODE ("Ry16 = add ( Ry16 , Ru16 ) ; Rx16 = add ( Rx16 , Rs16 )" , "00111000uuuuyyyyEE111000ssssxxxx"           , 0x1, 0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_addrx_SA1_addrx */
HEXAGON_OPCODE ("Ry32 = add ( Ru32 , mpyi ( Ry32 , Rs32 ) )" , "1110 0011 000sssss PP-yyyyy ---uuuuu"       , 0xc, 0, 0) /* M4_mpyrr_addr */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rf32 = #U6 )"       , "1001 1 01 0 100  fffff  PP01IIII  -IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignb_ap */
HEXAGON_MAPPING ("Ryy32 = memb_fifo ( Rs32 )"             , "0000yyyyysssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadalignb_zomap)) /* mapped to Ryy32=memb_fifo(Rs32+#0) */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rs32 + #s11:0 )"    , "1001 0 ii 0 100  sssss  PPiiiiii  iiiyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadalignb_io */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rt32 << #0 + #U6 )" , "1001 1 10 0 100  ttttt  PP01IIII  0IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignb_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rt32 << #1 + #U6 )" , "1001 1 10 0 100  ttttt  PP01IIII  1IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignb_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rt32 << #2 + #U6 )" , "1001 1 10 0 100  ttttt  PP11IIII  0IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignb_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rt32 << #3 + #U6 )" , "1001 1 10 0 100  ttttt  PP11IIII  1IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignb_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rz32 ++ #s4:0 )"    , "1001 1 01 0 100  zzzzz  PP00---i  iiiyyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignb_pi */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rz32 ++ #s4:0 :circ ( Mu2 ) )" , "1001 1 00 0 100  zzzzz  PPu0--0i  iiiyyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignb_pci */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rz32 ++ Mu2 )"      , "1001 1 10 0 100  zzzzz  PPu0----  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignb_pr */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rz32 ++ Mu2 :brev )" , "1001 1 11 0 100  zzzzz  PPu0----  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignb_pbr */
HEXAGON_OPCODE ("Ryy32 = memb_fifo ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 100  zzzzz  PPu0--1-  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignb_pcr */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rf32 = #U6 )"       , "1001 1 01 0 010  fffff  PP01IIII  -IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignh_ap */
HEXAGON_MAPPING ("Ryy32 = memh_fifo ( Rs32 )"             , "0000yyyyysssss000000000000000000"           , HEXAGON_MAP_FNAME(L2_loadalignh_zomap)) /* mapped to Ryy32=memh_fifo(Rs32+#0) */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rs32 + #s11:1 )"    , "1001 0 ii 0 010  sssss  PPiiiiii  iiiyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L2_loadalignh_io */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rt32 << #0 + #U6 )" , "1001 1 10 0 010  ttttt  PP01IIII  0IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignh_ur_expand_shamt_0 */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rt32 << #1 + #U6 )" , "1001 1 10 0 010  ttttt  PP01IIII  1IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignh_ur_expand_shamt_1 */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rt32 << #2 + #U6 )" , "1001 1 10 0 010  ttttt  PP11IIII  0IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignh_ur_expand_shamt_2 */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rt32 << #3 + #U6 )" , "1001 1 10 0 010  ttttt  PP11IIII  1IIyyyyy" , 0x3, 0, 0|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* L4_loadalignh_ur_expand_shamt_3 */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rz32 ++ #s4:1 )"    , "1001 1 01 0 010  zzzzz  PP00---i  iiiyyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignh_pi */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rz32 ++ #s4:1 :circ ( Mu2 ) )" , "1001 1 00 0 010  zzzzz  PPu0--0i  iiiyyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignh_pci */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rz32 ++ Mu2 )"      , "1001 1 10 0 010  zzzzz  PPu0----  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignh_pr */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rz32 ++ Mu2 :brev )" , "1001 1 11 0 010  zzzzz  PPu0----  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignh_pbr */
HEXAGON_OPCODE ("Ryy32 = memh_fifo ( Rz32 ++I :circ ( Mu2 ) )" , "1001 1 00 0 010  zzzzz  PPu0--1-  0--yyyyy" , 0x3, 0, 0|A_MEMORY) /* L2_loadalignh_pcr */
HEXAGON_OPCODE ("Sd64 = Rs32"                            , "0110 0111 00-sssss PP------ --dddddd"       , 0x8, 0, 0|A_RESTRICT_AX|A_RESTRICT_AX_SOMEREGS) /* Y2_tfrsrcr */
HEXAGON_OPCODE ("Sdd64 = Rss32"                          , "0110 1101 0--sssss PP------ --dddddd"       , 0x8, 0, 0|A_RESTRICT_AX|A_RESTRICT_AX_SOMEREGS) /* Y4_tfrspcp */
HEXAGON_OPCODE ("allocframe ( #u11:3 )"                  , "1010 000 01 0011101 PP000iii iiiiiiii"      , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY) /* S2_allocframe */
HEXAGON_OPCODE ("barrier"                                , "1010 100 00 00----- PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX) /* Y2_barrier */
HEXAGON_OPCODE ("brkpt"                                  , "0110 1100 001----- PP------ 000-----"       , 0x8, 0, 0|A_SOLO) /* Y2_break */
HEXAGON_OPCODE ("call #r22:2"                            , "0101 101i  iiiiiiii  PPiiiiii  iiiiiii0"    , 0xc, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_EXTENDABLE_LOWERCASE) /* J2_call */
HEXAGON_OPCODE ("callr Rs32"                             , "0101 0000  101sssss  PP------  --------"    , 0x4, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH) /* J2_callr */
HEXAGON_OPCODE ("ciad ( Rs32 )"                          , "0110 0100 000sssss PP------ 011-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_ciad */
HEXAGON_MAPPING ("crswap ( Rx32 , sgp )"                  , "0000xxxxx00000000000000000000000"           , HEXAGON_MAP_FNAME(Y2_crswap_old)) /* mapped to crswap(Rx32,sgp0) */
HEXAGON_OPCODE ("crswap ( Rx32 , sgp0 )"                 , "0110 0101 000xxxxx PP------ --------"       , 0x8, 0, 0) /* Y2_crswap0 */
HEXAGON_OPCODE ("crswap ( Rx32 , sgp1 )"                 , "0110 0101 001xxxxx PP------ --------"       , 0x8, 0, 0) /* Y4_crswap1 */
HEXAGON_OPCODE ("crswap ( Rxx32 , sgp1:0 )"              , "0110 1101 1--xxxxx PP------ ---00000"       , 0x8, 0, 0) /* Y4_crswap10 */
HEXAGON_OPCODE ("cswi ( Rs32 )"                          , "0110 0100 000sssss PP------ 001-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_cswi */
HEXAGON_OPCODE ("dccleana ( Rs32 )"                      , "1010 000 00 00sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_SLOT1_AONLY|A_MEMORY) /* Y2_dccleana */
HEXAGON_OPCODE ("dccleanidx ( Rs32 )"                    , "1010 001 00 01sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y2_dccleanidx */
HEXAGON_OPCODE ("dccleaninva ( Rs32 )"                   , "1010 000 00 10sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_SLOT1_AONLY|A_MEMORY) /* Y2_dccleaninva */
HEXAGON_OPCODE ("dccleaninvidx ( Rs32 )"                 , "1010 001 00 11sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y2_dccleaninvidx */
HEXAGON_MAPPING ("dcfetch ( Rs32 )"                       , "0000sssss00000000000000000000000"           , HEXAGON_MAP_FNAME(Y2_dcfetch)) /* mapped to dcfetch(Rs32+#0) */
HEXAGON_OPCODE ("dcfetch ( Rs32 + #u11:3 )"              , "1001 010 0 000 sssss PP0--iii iiiiiiii"     , 0x1, 0, 0|A_MEMORY) /* Y2_dcfetchbo */
HEXAGON_OPCODE ("dcinva ( Rs32 )"                        , "1010 000 00 01sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_SLOT1_AONLY|A_MEMORY) /* Y2_dcinva */
HEXAGON_OPCODE ("dcinvidx ( Rs32 )"                      , "1010 001 00 10sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y2_dcinvidx */
HEXAGON_OPCODE ("dckill"                                 , "1010 001 00 00----- PP------ --------"      , 0x1, 0, 0|A_SOLO) /* Y2_dckill */
HEXAGON_OPCODE ("dctagw ( Rs32 , Rt32 )"                 , "1010 010 00 00sssss PP-ttttt --------"      , 0x1, 0, 0|A_SOLO) /* Y2_dctagw */
HEXAGON_OPCODE ("dczeroa ( Rs32 )"                       , "1010 000 01 10sssss PP0----- --------"      , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_AONLY|A_MEMORY) /* Y2_dczeroa */
HEXAGON_OPCODE ("dealloc_return"                         , "1001 011 0 000 11110 PP0000-- ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_DEALLOCRET) /* L4_return */
HEXAGON_OPCODE ("deallocframe ; if ( ! p0 ) jumpr Lr"    , "0011111100---0--EE01111111---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SL2_jumpr31_f */
HEXAGON_OPCODE ("deallocframe ; if ( ! p0 .new ) jumpr:nt Lr" , "0011111100---0--EE01111111---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("deallocframe ; if ( p0 ) jumpr Lr"      , "0011111100---0--EE01111111---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SL2_jumpr31_t */
HEXAGON_OPCODE ("deallocframe ; if ( p0 .new ) jumpr:nt Lr" , "0011111100---0--EE01111111---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("deallocframe ; jumpr Lr"                , "0011111100---0--EE01111111---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_MEMORY|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SL2_jumpr31 */
HEXAGON_OPCODE ("deallocframe ; memb ( Rs16 + #u4:0 ) = #0" , "1101111100---0--EE110010ssssiiii"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storebi0 */
HEXAGON_OPCODE ("deallocframe ; memb ( Rs16 + #u4:0 ) = #1" , "1101111100---0--EE110011ssssiiii"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storebi1 */
HEXAGON_OPCODE ("deallocframe ; memb ( Rs16 + #u4:0 ) = Rt16" , "1001111100---0--EE11iiiisssstttt"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS1_storeb_io */
HEXAGON_OPCODE ("deallocframe ; memd ( Sp + #s6:3 ) = Rtt8" , "1101111100---0--EE10101iiiiiittt"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_stored_sp */
HEXAGON_OPCODE ("deallocframe ; memh ( Rs16 + #u3:1 ) = Rt16" , "1101111100---0--EE100iiisssstttt"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storeh_io */
HEXAGON_OPCODE ("deallocframe ; memw ( Rs16 + #u4:2 ) = #0" , "1101111100---0--EE110000ssssiiii"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storewi0 */
HEXAGON_OPCODE ("deallocframe ; memw ( Rs16 + #u4:2 ) = #1" , "1101111100---0--EE110001ssssiiii"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storewi1 */
HEXAGON_OPCODE ("deallocframe ; memw ( Rs16 + #u4:2 ) = Rt16" , "1001111100---0--EE10iiiisssstttt"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS1_storew_io */
HEXAGON_OPCODE ("deallocframe ; memw ( Sp + #u5:2 ) = Rt16" , "1101111100---0--EE10100iiiiitttt"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SL2_deallocframe_SS2_storew_sp */
HEXAGON_OPCODE ("deallocframe"                           , "1001 000 0 000 11110 PP0----- ---11110"     , 0x3, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY) /* L2_deallocframe */
HEXAGON_OPCODE ("hintjr ( Rs32 )"                        , "0101 0010  101sssss  PP------  --------"    , 0x4, 0, 0|A_BRANCH) /* J4_hintjumpr */
HEXAGON_OPCODE ("iassignw ( Rs32 )"                      , "0110 0100 000sssss PP------ 010-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_iassignw */
HEXAGON_OPCODE ("icinva ( Rs32 )"                        , "0101 0110  110sssss  PP000---  --------"    , 0x4, 0, 0|A_SOLO) /* Y2_icinva */
HEXAGON_OPCODE ("icinvidx ( Rs32 )"                      , "0101 0110  110sssss  PP001---  --------"    , 0x4, 0, 0|A_SOLO) /* Y2_icinvidx */
HEXAGON_OPCODE ("ickill"                                 , "0101 0110  110-----  PP010---  --------"    , 0x4, 0, 0|A_SOLO) /* Y2_ickill */
HEXAGON_OPCODE ("ictagw ( Rs32 , Rt32 )"                 , "0101 0101  110sssss  PP-ttttt  --------"    , 0x4, 0, 0|A_SOLO) /* Y2_ictagw */
HEXAGON_OPCODE ("if ! Ps4 .new dealloc_return:nt"        , "1001 011 0 000 11110 PP1010ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_fnew_pnt_alt */
HEXAGON_OPCODE ("if ! Ps4 .new dealloc_return:t"         , "1001 011 0 000 11110 PP1110ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_fnew_pt_alt */
HEXAGON_OPCODE ("if ! Ps4 dealloc_return"                , "1001 011 0 000 11110 PP1100ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_DEALLOCRET) /* L4_return_f_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memb ( #u6 )"      , "1001 1 11 1 000  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rd32 = memb ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbfnew_zomap_alt)) /* mapped to if (!Pt4.new) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0111 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbfnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrbfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memh ( #u6 )"      , "1001 1 11 1 010  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rd32 = memh ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhfnew_zomap_alt)) /* mapped to if (!Pt4.new) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0111 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrhfnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrhfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memub ( #u6 )"     , "1001 1 11 1 001  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rd32 = memub ( Rs32 )"    , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubfnew_zomap_alt)) /* mapped to if (!Pt4.new) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0111 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubfnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrubfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memuh ( #u6 )"     , "1001 1 11 1 011  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rd32 = memuh ( Rs32 )"    , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhfnew_zomap_alt)) /* mapped to if (!Pt4.new) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0111 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadruhfnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadruhfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memw ( #u6 )"      , "1001 1 11 1 100  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrifnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rd32 = memw ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrifnew_zomap_alt)) /* mapped to if (!Pt4.new) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0111 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrifnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrifnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rdd32 = memd ( #u6 )"     , "1001 1 11 1 110  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 .new Rdd32 = memd ( Rs32 )"    , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdfnew_zomap_alt)) /* mapped to if (!Pt4.new) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 .new Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0111 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdfnew_io_alt */
HEXAGON_OPCODE ("if ! Pt4 .new Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrdfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memb ( #u6 )"           , "1001 1 11 1 000  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbf_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rd32 = memb ( Rs32 )"          , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbf_zomap_alt)) /* mapped to if (!Pt4) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memb ( Rs32 + #u6:0 )"  , "0100 0101 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrbf_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrbf_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memh ( #u6 )"           , "1001 1 11 1 010  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhf_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rd32 = memh ( Rs32 )"          , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhf_zomap_alt)) /* mapped to if (!Pt4) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memh ( Rs32 + #u6:1 )"  , "0100 0101 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrhf_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrhf_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memub ( #u6 )"          , "1001 1 11 1 001  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubf_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rd32 = memub ( Rs32 )"         , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubf_zomap_alt)) /* mapped to if (!Pt4) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0101 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrubf_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrubf_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memuh ( #u6 )"          , "1001 1 11 1 011  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhf_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rd32 = memuh ( Rs32 )"         , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhf_zomap_alt)) /* mapped to if (!Pt4) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0101 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadruhf_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadruhf_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memw ( #u6 )"           , "1001 1 11 1 100  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrif_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rd32 = memw ( Rs32 )"          , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrif_zomap_alt)) /* mapped to if (!Pt4) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memw ( Rs32 + #u6:2 )"  , "0100 0101 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrif_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrif_pi_alt */
HEXAGON_OPCODE ("if ! Pt4 Rdd32 = memd ( #u6 )"          , "1001 1 11 1 110  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdf_abs_alt */
HEXAGON_MAPPING ("if ! Pt4 Rdd32 = memd ( Rs32 )"         , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdf_zomap_alt)) /* mapped to if (!Pt4) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ! Pt4 Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0101 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrdf_io_alt */
HEXAGON_OPCODE ("if ! Pt4 Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrdf_pi_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = #s12"              , "0111 1110 1uu0iiii PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* C2_cmovenewif_alt */
HEXAGON_MAPPING ("if ! Pu4 .new Rd32 = Rs32"              , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrfnew_alt)) /* mapped to if (!Pu4.new) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = add ( Rs32 , #s8 )" , "0111 0100 1uusssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* A2_paddifnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = add ( Rs32 , Rt32 )" , "1111 1011  0-0sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_paddfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = and ( Rs32 , Rt32 )" , "1111 1001  -00sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_pandfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = aslh ( Rs32 )"     , "0111 0000  000sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_paslhfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = asrh ( Rs32 )"     , "0111 0000  001sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pasrhfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = or ( Rs32 , Rt32 )" , "1111 1001  -01sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_porfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = sub ( Rt32 , Rs32 )" , "1111 1011  0-1sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_psubfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = sxtb ( Rs32 )"     , "0111 0000  101sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_psxtbfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = sxth ( Rs32 )"     , "0111 0000  111sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_psxthfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = xor ( Rs32 , Rt32 )" , "1111 1001  -11sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_pxorfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = zxtb ( Rs32 )"     , "0111 0000  100sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pzxtbfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new Rd32 = zxth ( Rs32 )"     , "0111 0000  110sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pzxthfnew_alt */
HEXAGON_MAPPING ("if ! Pu4 .new Rdd32 = Rss32"            , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpfnew_alt)) /* mapped to if (!Pu4.new) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ! Pu4 .new Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* C2_ccombinewnewf_alt */
HEXAGON_OPCODE ("if ! Pu4 .new jump:nt #r15:2"           , "0101 1100  ii1iiiii  PPi01-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumpfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new jump:t #r15:2"            , "0101 1100  ii1iiiii  PPi11-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumpfnewpt_alt */
HEXAGON_OPCODE ("if ! Pu4 .new jumpr:nt Rs32"            , "0101 0011  011sssss  PP-01-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* J2_jumprfnew_alt */
HEXAGON_OPCODE ("if ! Pu4 .new jumpr:t Rs32"             , "0101 0011  011sssss  PP-11-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* J2_jumprfnewpt_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = #s12"                   , "0111 1110 1uu0iiii PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* C2_cmoveif_alt */
HEXAGON_MAPPING ("if ! Pu4 Rd32 = Rs32"                   , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrf_alt)) /* mapped to if (!Pu4) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = add ( Rs32 , #s8 )"     , "0111 0100 1uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* A2_paddif_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = add ( Rs32 , Rt32 )"    , "1111 1011  0-0sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_paddf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = and ( Rs32 , Rt32 )"    , "1111 1001  -00sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_pandf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = aslh ( Rs32 )"          , "0111 0000  000sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_paslhf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = asrh ( Rs32 )"          , "0111 0000  001sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pasrhf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = or ( Rs32 , Rt32 )"     , "1111 1001  -01sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_porf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = sub ( Rt32 , Rs32 )"    , "1111 1011  0-1sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_psubf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = sxtb ( Rs32 )"          , "0111 0000  101sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_psxtbf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = sxth ( Rs32 )"          , "0111 0000  111sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_psxthf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = xor ( Rs32 , Rt32 )"    , "1111 1001  -11sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_pxorf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = zxtb ( Rs32 )"          , "0111 0000  100sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pzxtbf_alt */
HEXAGON_OPCODE ("if ! Pu4 Rd32 = zxth ( Rs32 )"          , "0111 0000  110sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pzxthf_alt */
HEXAGON_MAPPING ("if ! Pu4 Rdd32 = Rss32"                 , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpf_alt)) /* mapped to if (!Pu4) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ! Pu4 Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* C2_ccombinewf_alt */
HEXAGON_OPCODE ("if ! Pu4 call #r15:2"                   , "0101 1101  ii1iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* J2_callf_alt */
HEXAGON_OPCODE ("if ! Pu4 callr Rs32"                    , "0101 0001  001sssss  PP----uu  --------"    , 0x4, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED ) /* J2_callrf_alt */
HEXAGON_OPCODE ("if ! Pu4 jump #r15:2"                   , "0101 1100  ii1iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* J2_jumpf_alt */
HEXAGON_OPCODE ("if ! Pu4 jumpr Rs32"                    , "0101 0011  011sssss  PP--0-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED ) /* J2_jumprf_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 11 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 11 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 11 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 11 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 11 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 11 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 11 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 11 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 11 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 11 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 11 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 11 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 11 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 11 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 11 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 11 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 11 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 11 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 11 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 11 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 11 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 11 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 11 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 11 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( #u6 ) = Nt8 .new"  , "1010 1 11 1 101  ---ii  PP100ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewfnew_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( #u6 ) = Rt32"      , "1010 1 11 1 000  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 .new memb ( Rs32 ) = #S6"      , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbfnew_zomap_alt)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 .new memb ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbnewfnew_zomap_alt)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 .new memb ( Rs32 ) = Rt32"     , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbfnew_zomap_alt)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 11  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirbfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0110 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbnewfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0110 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerbnewfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerbfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( #u6 ) = Rtt32"     , "1010 1 11 1 110  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 .new memd ( Rs32 ) = Rtt32"    , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerdfnew_zomap_alt)) /* mapped to if (!Pv4.new) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0110 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerdfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 11 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 11 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 11 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 11 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerdfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( #u6 ) = Nt8 .new"  , "1010 1 11 1 101  ---ii  PP101ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewfnew_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( #u6 ) = Rt32.h"    , "1010 1 11 1 011  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerffnew_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( #u6 ) = Rt32"      , "1010 1 11 1 010  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhfnew_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 .new memh ( Rs32 ) = #S6"      , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhfnew_zomap_alt)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 .new memh ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhnewfnew_zomap_alt)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 .new memh ( Rs32 ) = Rt32.h"   , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerffnew_zomap_alt)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ! Pv4 .new memh ( Rs32 ) = Rt32"     , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhfnew_zomap_alt)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 11  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirhfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0110 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhnewfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0110 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerffnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0110 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 11 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 11 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 11 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 11 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerhnewfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerffnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerhfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( #u6 ) = Nt8 .new"  , "1010 1 11 1 101  ---ii  PP110ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewfnew_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( #u6 ) = Rt32"      , "1010 1 11 1 100  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerifnew_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 .new memw ( Rs32 ) = #S6"      , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirifnew_zomap_alt)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 .new memw ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerinewfnew_zomap_alt)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 .new memw ( Rs32 ) = Rt32"     , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerifnew_zomap_alt)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 11  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirifnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0110 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerinewfnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0110 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerifnew_io_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerinewfnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 .new memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerifnew_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 01 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 01 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 01 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 01 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 01 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 01 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 01 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 01 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 01 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 01 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 01 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 01 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 01 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 01 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 01 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 01 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 01 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 01 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 01 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 01 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 01 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 01 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 01 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 01 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( #u6 ) = Nt8 .new"       , "1010 1 11 1 101  ---ii  PP000ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewf_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( #u6 ) = Rt32"           , "1010 1 11 1 000  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbf_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 memb ( Rs32 ) = #S6"           , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbf_zomap_alt)) /* mapped to if (!Pv4) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 memb ( Rs32 ) = Nt8 .new"      , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbnewf_zomap_alt)) /* mapped to if (!Pv4) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 memb ( Rs32 ) = Rt32"          , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbf_zomap_alt)) /* mapped to if (!Pv4) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + #u6:0 ) = #S6"   , "0011 100 01  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirbf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0100 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerbnewf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + #u6:0 ) = Rt32"  , "0100 0100 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerbf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerbnewf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerbf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( #u6 ) = Rtt32"          , "1010 1 11 1 110  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdf_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 memd ( Rs32 ) = Rtt32"         , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerdf_zomap_alt)) /* mapped to if (!Pv4) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0100 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerdf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 01 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 01 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 01 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 01 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerdf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( #u6 ) = Nt8 .new"       , "1010 1 11 1 101  ---ii  PP001ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewf_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( #u6 ) = Rt32.h"         , "1010 1 11 1 011  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerff_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( #u6 ) = Rt32"           , "1010 1 11 1 010  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhf_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 memh ( Rs32 ) = #S6"           , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhf_zomap_alt)) /* mapped to if (!Pv4) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 memh ( Rs32 ) = Nt8 .new"      , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhnewf_zomap_alt)) /* mapped to if (!Pv4) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 memh ( Rs32 ) = Rt32.h"        , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerff_zomap_alt)) /* mapped to if (!Pv4) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ! Pv4 memh ( Rs32 ) = Rt32"          , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhf_zomap_alt)) /* mapped to if (!Pv4) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + #u6:1 ) = #S6"   , "0011 100 01  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirhf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0100 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerhnewf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0100 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerff_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + #u6:1 ) = Rt32"  , "0100 0100 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerhf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 01 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 01 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 01 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 01 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerhnewf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerff_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerhf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( #u6 ) = Nt8 .new"       , "1010 1 11 1 101  ---ii  PP010ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewf_abs_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( #u6 ) = Rt32"           , "1010 1 11 1 100  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerif_abs_alt */
HEXAGON_MAPPING ("if ! Pv4 memw ( Rs32 ) = #S6"           , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirif_zomap_alt)) /* mapped to if (!Pv4) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ! Pv4 memw ( Rs32 ) = Nt8 .new"      , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerinewf_zomap_alt)) /* mapped to if (!Pv4) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ! Pv4 memw ( Rs32 ) = Rt32"          , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerif_zomap_alt)) /* mapped to if (!Pv4) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + #u6:2 ) = #S6"   , "0011 100 01  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirif_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0100 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerinewf_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + #u6:2 ) = Rt32"  , "0100 0100 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerif_io_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerinewf_pi_alt */
HEXAGON_OPCODE ("if ! Pv4 memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerif_pi_alt */
HEXAGON_OPCODE ("if ( ! Ps4 ) dealloc_return"            , "1001 011 0 000 11110 PP1100ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_DEALLOCRET) /* L4_return_f */
HEXAGON_OPCODE ("if ( ! Ps4 .new ) dealloc_return:nt"    , "1001 011 0 000 11110 PP1010ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_fnew_pnt */
HEXAGON_OPCODE ("if ( ! Ps4 .new ) dealloc_return:t"     , "1001 011 0 000 11110 PP1110ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_fnew_pt */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memb ( #u6 )"       , "1001 1 11 1 000  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbf_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rd32 = memb ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbf_zomap)) /* mapped to if (!Pt4) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0101 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrbf_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrbf_pi */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memh ( #u6 )"       , "1001 1 11 1 010  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhf_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rd32 = memh ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhf_zomap)) /* mapped to if (!Pt4) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0101 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrhf_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrhf_pi */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memub ( #u6 )"      , "1001 1 11 1 001  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubf_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rd32 = memub ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubf_zomap)) /* mapped to if (!Pt4) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0101 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrubf_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrubf_pi */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memuh ( #u6 )"      , "1001 1 11 1 011  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhf_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rd32 = memuh ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhf_zomap)) /* mapped to if (!Pt4) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0101 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadruhf_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadruhf_pi */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memw ( #u6 )"       , "1001 1 11 1 100  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrif_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rd32 = memw ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrif_zomap)) /* mapped to if (!Pt4) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0101 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrif_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrif_pi */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rdd32 = memd ( #u6 )"      , "1001 1 11 1 110  iiiii  PP101tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdf_abs */
HEXAGON_MAPPING ("if ( ! Pt4 ) Rdd32 = memd ( Rs32 )"     , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdf_zomap)) /* mapped to if (!Pt4) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0101 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* L2_ploadrdf_io */
HEXAGON_OPCODE ("if ( ! Pt4 ) Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP101tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L2_ploadrdf_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memb ( #u6 )"  , "1001 1 11 1 000  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbfnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rd32 = memb ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbfnew_zomap)) /* mapped to if (!Pt4.new) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0111 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbfnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrbfnew_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memh ( #u6 )"  , "1001 1 11 1 010  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhfnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rd32 = memh ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhfnew_zomap)) /* mapped to if (!Pt4.new) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0111 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrhfnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrhfnew_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memub ( #u6 )" , "1001 1 11 1 001  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubfnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rd32 = memub ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubfnew_zomap)) /* mapped to if (!Pt4.new) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0111 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubfnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrubfnew_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memuh ( #u6 )" , "1001 1 11 1 011  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhfnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rd32 = memuh ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhfnew_zomap)) /* mapped to if (!Pt4.new) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0111 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadruhfnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadruhfnew_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memw ( #u6 )"  , "1001 1 11 1 100  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrifnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rd32 = memw ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrifnew_zomap)) /* mapped to if (!Pt4.new) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0111 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrifnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrifnew_pi */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rdd32 = memd ( #u6 )" , "1001 1 11 1 110  iiiii  PP111tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdfnew_abs */
HEXAGON_MAPPING ("if ( ! Pt4 .new ) Rdd32 = memd ( Rs32 )" , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdfnew_zomap)) /* mapped to if (!Pt4.new) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0111 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdfnew_io */
HEXAGON_OPCODE ("if ( ! Pt4 .new ) Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP111tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L2_ploadrdfnew_pi */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = #s12"               , "0111 1110 1uu0iiii PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* C2_cmoveif */
HEXAGON_MAPPING ("if ( ! Pu4 ) Rd32 = Rs32"               , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrf)) /* mapped to if (!Pu4) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = add ( Rs32 , #s8 )" , "0111 0100 1uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* A2_paddif */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = add ( Rs32 , Rt32 )" , "1111 1011  0-0sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_paddf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = and ( Rs32 , Rt32 )" , "1111 1001  -00sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_pandf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = aslh ( Rs32 )"      , "0111 0000  000sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_paslhf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = asrh ( Rs32 )"      , "0111 0000  001sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pasrhf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = or ( Rs32 , Rt32 )" , "1111 1001  -01sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_porf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = sub ( Rt32 , Rs32 )" , "1111 1011  0-1sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_psubf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = sxtb ( Rs32 )"      , "0111 0000  101sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_psxtbf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = sxth ( Rs32 )"      , "0111 0000  111sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_psxthf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = xor ( Rs32 , Rt32 )" , "1111 1001  -11sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A2_pxorf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = zxtb ( Rs32 )"      , "0111 0000  100sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pzxtbf */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rd32 = zxth ( Rs32 )"      , "0111 0000  110sssss  PP1-10uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* A4_pzxthf */
HEXAGON_MAPPING ("if ( ! Pu4 ) Rdd32 = Rss32"             , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpf)) /* mapped to if (!Pu4) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ( ! Pu4 ) Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP0ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED ) /* C2_ccombinewf */
HEXAGON_OPCODE ("if ( ! Pu4 ) call #r15:2"               , "0101 1101  ii1iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* J2_callf */
HEXAGON_OPCODE ("if ( ! Pu4 ) callr Rs32"                , "0101 0001  001sssss  PP----uu  --------"    , 0x4, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED ) /* J2_callrf */
HEXAGON_OPCODE ("if ( ! Pu4 ) jump #r15:2"               , "0101 1100  ii1iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* J2_jumpf */
HEXAGON_OPCODE ("if ( ! Pu4 ) jumpr Rs32"                , "0101 0011  011sssss  PP--0-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED ) /* J2_jumprf */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = #s12"          , "0111 1110 1uu0iiii PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* C2_cmovenewif */
HEXAGON_MAPPING ("if ( ! Pu4 .new ) Rd32 = Rs32"          , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrfnew)) /* mapped to if (!Pu4.new) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = add ( Rs32 , #s8 )" , "0111 0100 1uusssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* A2_paddifnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = add ( Rs32 , Rt32 )" , "1111 1011  0-0sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_paddfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = and ( Rs32 , Rt32 )" , "1111 1001  -00sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_pandfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = aslh ( Rs32 )" , "0111 0000  000sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_paslhfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = asrh ( Rs32 )" , "0111 0000  001sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pasrhfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = or ( Rs32 , Rt32 )" , "1111 1001  -01sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_porfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = sub ( Rt32 , Rs32 )" , "1111 1011  0-1sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_psubfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = sxtb ( Rs32 )" , "0111 0000  101sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_psxtbfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = sxth ( Rs32 )" , "0111 0000  111sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_psxthfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = xor ( Rs32 , Rt32 )" , "1111 1001  -11sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A2_pxorfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = zxtb ( Rs32 )" , "0111 0000  100sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pzxtbfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rd32 = zxth ( Rs32 )" , "0111 0000  110sssss  PP1-11uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* A4_pzxthfnew */
HEXAGON_MAPPING ("if ( ! Pu4 .new ) Rdd32 = Rss32"        , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpfnew)) /* mapped to if (!Pu4.new) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP1ttttt 1uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* C2_ccombinewnewf */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) jump:nt #r15:2"       , "0101 1100  ii1iiiii  PPi01-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumpfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) jump:t #r15:2"        , "0101 1100  ii1iiiii  PPi11-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumpfnewpt */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) jumpr:nt Rs32"        , "0101 0011  011sssss  PP-01-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* J2_jumprfnew */
HEXAGON_OPCODE ("if ( ! Pu4 .new ) jumpr:t Rs32"         , "0101 0011  011sssss  PP-11-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* J2_jumprfnewpt */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 01 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 01 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 01 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 01 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrbf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 01 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 01 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 01 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 01 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrhf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 01 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 01 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 01 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 01 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrubf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 01 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 01 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 01 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 01 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadruhf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 01 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 01 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 01 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 01 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrif_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 01 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 01 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 01 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 01 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* L4_ploadrdf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( #u6 ) = Nt8 .new"   , "1010 1 11 1 101  ---ii  PP000ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewf_abs */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( #u6 ) = Rt32"       , "1010 1 11 1 000  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbf_abs */
HEXAGON_MAPPING ("if ( ! Pv4 ) memb ( Rs32 ) = #S6"       , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbf_zomap)) /* mapped to if (!Pv4) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 ) memb ( Rs32 ) = Nt8 .new"  , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbnewf_zomap)) /* mapped to if (!Pv4) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 ) memb ( Rs32 ) = Rt32"      , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbf_zomap)) /* mapped to if (!Pv4) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 01  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirbf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0100 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerbnewf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0100 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerbf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbnewf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerbf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerbnewf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerbf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( #u6 ) = Rtt32"      , "1010 1 11 1 110  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdf_abs */
HEXAGON_MAPPING ("if ( ! Pv4 ) memd ( Rs32 ) = Rtt32"     , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerdf_zomap)) /* mapped to if (!Pv4) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0100 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerdf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 01 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 01 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 01 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 01 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerdf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerdf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( #u6 ) = Nt8 .new"   , "1010 1 11 1 101  ---ii  PP001ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewf_abs */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( #u6 ) = Rt32.h"     , "1010 1 11 1 011  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerff_abs */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( #u6 ) = Rt32"       , "1010 1 11 1 010  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhf_abs */
HEXAGON_MAPPING ("if ( ! Pv4 ) memh ( Rs32 ) = #S6"       , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhf_zomap)) /* mapped to if (!Pv4) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 ) memh ( Rs32 ) = Nt8 .new"  , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhnewf_zomap)) /* mapped to if (!Pv4) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 ) memh ( Rs32 ) = Rt32.h"    , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerff_zomap)) /* mapped to if (!Pv4) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ( ! Pv4 ) memh ( Rs32 ) = Rt32"      , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhf_zomap)) /* mapped to if (!Pv4) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 01  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirhf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0100 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerhnewf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0100 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerff_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0100 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerhf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 01 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 01 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 01 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhnewf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 01 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerff_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerhf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerhnewf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerff_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerhf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( #u6 ) = Nt8 .new"   , "1010 1 11 1 101  ---ii  PP010ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewf_abs */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( #u6 ) = Rt32"       , "1010 1 11 1 100  ---ii  PP0ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerif_abs */
HEXAGON_MAPPING ("if ( ! Pv4 ) memw ( Rs32 ) = #S6"       , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirif_zomap)) /* mapped to if (!Pv4) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 ) memw ( Rs32 ) = Nt8 .new"  , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerinewf_zomap)) /* mapped to if (!Pv4) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 ) memw ( Rs32 ) = Rt32"      , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerif_zomap)) /* mapped to if (!Pv4) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 01  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_UPPERCASE) /* S4_storeirif_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0100 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerinewf_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0100 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_EXTENDABLE_LOWERCASE) /* S2_pstorerif_io */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 01 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 01 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 01 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 01 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 01 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerinewf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 01 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S4_pstorerif_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  0iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerinewf_pi */
HEXAGON_OPCODE ("if ( ! Pv4 ) memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  0iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED ) /* S2_pstorerif_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 11 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 11 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 11 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 11 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrbfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 11 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 11 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 11 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 11 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrhfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 11 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 11 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 11 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 11 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrubfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 11 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 11 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 11 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 11 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadruhfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 11 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 11 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 11 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 11 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrifnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 11 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 11 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 11 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 11 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* L4_ploadrdfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP100ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewfnew_abs */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( #u6 ) = Rt32"  , "1010 1 11 1 000  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbfnew_abs */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memb ( Rs32 ) = #S6"  , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbfnew_zomap)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memb ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbnewfnew_zomap)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memb ( Rs32 ) = Rt32" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbfnew_zomap)) /* mapped to if (!Pv4.new) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 11  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirbfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0110 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbnewfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0110 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbnewfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerbfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerbnewfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerbfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( #u6 ) = Rtt32" , "1010 1 11 1 110  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdfnew_abs */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memd ( Rs32 ) = Rtt32" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerdfnew_zomap)) /* mapped to if (!Pv4.new) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0110 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerdfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 11 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 11 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 11 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 11 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerdfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerdfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP101ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewfnew_abs */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( #u6 ) = Rt32.h" , "1010 1 11 1 011  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerffnew_abs */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( #u6 ) = Rt32"  , "1010 1 11 1 010  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhfnew_abs */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memh ( Rs32 ) = #S6"  , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhfnew_zomap)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memh ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhnewfnew_zomap)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memh ( Rs32 ) = Rt32.h" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerffnew_zomap)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memh ( Rs32 ) = Rt32" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhfnew_zomap)) /* mapped to if (!Pv4.new) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 11  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirhfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0110 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhnewfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0110 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerffnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0110 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 11 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 11 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 11 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhnewfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 11 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerffnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerhfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerhnewfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerffnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerhfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP110ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewfnew_abs */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( #u6 ) = Rt32"  , "1010 1 11 1 100  ---ii  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerifnew_abs */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memw ( Rs32 ) = #S6"  , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirifnew_zomap)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memw ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerinewfnew_zomap)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( ! Pv4 .new ) memw ( Rs32 ) = Rt32" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerifnew_zomap)) /* mapped to if (!Pv4.new) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 11  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirifnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0110 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerinewfnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0110 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerifnew_io */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 11 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 11 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 11 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 11 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 11 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerinewfnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 11 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S4_pstorerifnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  1iiii1vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerinewfnew_pi */
HEXAGON_OPCODE ("if ( ! Pv4 .new ) memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  1iiii1vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW) /* S2_pstorerifnew_pi */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , #-1 ) ) jump:nt #r9:2" , "0010 -1 100  1ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , #-1 ) ) jump:t #r9:2" , "0010 -1 100  1ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 000  1ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 000  1ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 000  1ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.eq ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 000  1ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , #-1 ) ) jump:nt #r9:2" , "0010 -1 101  1ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , #-1 ) ) jump:t #r9:2" , "0010 -1 101  1ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 001  1ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 001  1ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 001  1ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 001  1ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Rt32 , Ns8 .new ) ) jump:nt #r9:2" , "0010 -0 011  1ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmplt_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gt ( Rt32 , Ns8 .new ) ) jump:t #r9:2" , "0010 -0 011  1ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmplt_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 010  1ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 010  1ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 010  1ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 010  1ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Rt32 , Ns8 .new ) ) jump:nt #r9:2" , "0010 -0 100  1ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpltu_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! cmp.gtu ( Rt32 , Ns8 .new ) ) jump:t #r9:2" , "0010 -0 100  1ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpltu_f_jumpnv_t */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; allocframe ( #u5:3 )" , "0111101--111ddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_allocframe */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; dealloc_return" , "0101101--111ddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrf_SL2_return */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; deallocframe"   , "0101101--111ddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_deallocframe */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( ! p0 ) dealloc_return" , "0101101--111ddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrf_SL2_return_f */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( ! p0 ) jumpr Lr" , "0101101--111ddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_jumpr31_f */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( ! p0 .new ) dealloc_return:nt" , "0101101--111ddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrf_SL2_return_fnew */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( ! p0 .new ) jumpr:nt Lr" , "0101101--111ddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( p0 ) dealloc_return" , "0101101--111ddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrf_SL2_return_t */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( p0 ) jumpr Lr" , "0101101--111ddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_jumpr31_t */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( p0 .new ) dealloc_return:nt" , "0101101--111ddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrf_SL2_return_tnew */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; if ( p0 .new ) jumpr:nt Lr" , "0101101--111ddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; jumpr Lr"       , "0101101--111ddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_jumpr31 */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "0111101--111ddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storebi0 */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "0111101--111ddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storebi1 */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = Rt16" , "0111101--111ddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS1_storeb_io */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "0111101--111ddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_stored_sp */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "0111101--111ddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storeh_io */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "0111101--111ddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storewi0 */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "0111101--111ddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storewi1 */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = Rt16" , "0111101--111ddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS1_storew_io */
HEXAGON_OPCODE ("if ( ! p0 ) Rd16 = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "0111101--111ddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SS2_storew_sp */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memb ( Rs16 + #u3:0 )" , "0101101--111eeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_loadrb_io */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memh ( Rs16 + #u3:1 )" , "0101101--111eeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_loadrh_io */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memub ( Rs16 + #u4:0 )" , "0101101--111eeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL1_loadrub_io */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0101101--111eeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_loadruh_io */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memw ( Rs16 + #u4:2 )" , "0101101--111eeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL1_loadri_io */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rd16 = memw ( Sp + #u5:2 )" , "0101101--111eeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_loadri_sp */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( #0 , #u2 )" , "0011101--111eeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combine0i */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( #0 , Rs16 )" , "0011101--111eeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combinezr */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( #1 , #u2 )" , "0011101--111eeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combine1i */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( #2 , #u2 )" , "0011101--111eeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combine2i */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( #3 , #u2 )" , "0011101--111eeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combine3i */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = combine ( Rs16 , #0 )" , "0011101--111eeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_combinerz */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; Rdd8 = memd ( Sp + #u5:3 )" , "0101101--111eeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SL2_loadrd_sp */
HEXAGON_OPCODE ("if ( ! p0 ) Re16 = #0 ; if ( ! p0 ) Rd16 = #0" , "0011101--111eeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrf_SA1_clrf */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; allocframe ( #u5:3 )" , "0111101--101ddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_allocframe */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; dealloc_return" , "0101101--101ddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrfnew_SL2_return */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; deallocframe" , "0101101--101ddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_deallocframe */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( ! p0 ) dealloc_return" , "0101101--101ddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrfnew_SL2_return_f */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( ! p0 ) jumpr Lr" , "0101101--101ddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_jumpr31_f */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( ! p0 .new ) dealloc_return:nt" , "0101101--101ddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrfnew_SL2_return_fnew */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( ! p0 .new ) jumpr:nt Lr" , "0101101--101ddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( p0 ) dealloc_return" , "0101101--101ddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrfnew_SL2_return_t */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( p0 ) jumpr Lr" , "0101101--101ddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_jumpr31_t */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( p0 .new ) dealloc_return:nt" , "0101101--101ddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrfnew_SL2_return_tnew */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; if ( p0 .new ) jumpr:nt Lr" , "0101101--101ddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; jumpr Lr"  , "0101101--101ddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_jumpr31 */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "0111101--101ddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storebi0 */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "0111101--101ddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storebi1 */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = Rt16" , "0111101--101ddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS1_storeb_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "0111101--101ddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_stored_sp */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "0111101--101ddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storeh_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "0111101--101ddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storewi0 */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "0111101--101ddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storewi1 */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = Rt16" , "0111101--101ddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS1_storew_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Rd16 = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "0111101--101ddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SS2_storew_sp */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memb ( Rs16 + #u3:0 )" , "0101101--101eeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_loadrb_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memh ( Rs16 + #u3:1 )" , "0101101--101eeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_loadrh_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memub ( Rs16 + #u4:0 )" , "0101101--101eeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL1_loadrub_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0101101--101eeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_loadruh_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memw ( Rs16 + #u4:2 )" , "0101101--101eeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL1_loadri_io */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rd16 = memw ( Sp + #u5:2 )" , "0101101--101eeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_loadri_sp */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( #0 , #u2 )" , "0011101--101eeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combine0i */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( #0 , Rs16 )" , "0011101--101eeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combinezr */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( #1 , #u2 )" , "0011101--101eeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combine1i */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( #2 , #u2 )" , "0011101--101eeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combine2i */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( #3 , #u2 )" , "0011101--101eeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combine3i */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = combine ( Rs16 , #0 )" , "0011101--101eeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_combinerz */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; Rdd8 = memd ( Sp + #u5:3 )" , "0101101--101eeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SL2_loadrd_sp */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; if ( ! p0 ) Rd16 = #0" , "0011101--101eeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_clrf */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; if ( ! p0 .new ) Rd16 = #0" , "0011101--101eeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_clrfnew */
HEXAGON_OPCODE ("if ( ! p0 .new ) Re16 = #0 ; if ( p0 ) Rd16 = #0" , "0011101--101eeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrfnew_SA1_clrt */
HEXAGON_OPCODE ("if ( ! tstbit ( Ns8 .new , #0 ) ) jump:nt #r9:2" , "0010 -1 011  1ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_f_jumpnv_nt */
HEXAGON_OPCODE ("if ( ! tstbit ( Ns8 .new , #0 ) ) jump:t #r9:2" , "0010 -1 011  1ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_f_jumpnv_t */
HEXAGON_OPCODE ("if ( Ps4 ) dealloc_return"              , "1001 011 0 000 11110 PP0100ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_DEALLOCRET) /* L4_return_t */
HEXAGON_OPCODE ("if ( Ps4 .new ) dealloc_return:nt"      , "1001 011 0 000 11110 PP0010ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_tnew_pnt */
HEXAGON_OPCODE ("if ( Ps4 .new ) dealloc_return:t"       , "1001 011 0 000 11110 PP0110ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_tnew_pt */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memb ( #u6 )"         , "1001 1 11 1 000  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbt_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rd32 = memb ( Rs32 )"        , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbt_zomap)) /* mapped to if (Pt4) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0001 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbt_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrbt_pi */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memh ( #u6 )"         , "1001 1 11 1 010  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrht_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rd32 = memh ( Rs32 )"        , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrht_zomap)) /* mapped to if (Pt4) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0001 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrht_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrht_pi */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memub ( #u6 )"        , "1001 1 11 1 001  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubt_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rd32 = memub ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubt_zomap)) /* mapped to if (Pt4) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0001 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubt_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrubt_pi */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memuh ( #u6 )"        , "1001 1 11 1 011  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruht_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rd32 = memuh ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruht_zomap)) /* mapped to if (Pt4) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0001 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadruht_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadruht_pi */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memw ( #u6 )"         , "1001 1 11 1 100  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrit_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rd32 = memw ( Rs32 )"        , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrit_zomap)) /* mapped to if (Pt4) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0001 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrit_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrit_pi */
HEXAGON_OPCODE ("if ( Pt4 ) Rdd32 = memd ( #u6 )"        , "1001 1 11 1 110  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdt_abs */
HEXAGON_MAPPING ("if ( Pt4 ) Rdd32 = memd ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdt_zomap)) /* mapped to if (Pt4) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 ) Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0001 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdt_io */
HEXAGON_OPCODE ("if ( Pt4 ) Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrdt_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memb ( #u6 )"    , "1001 1 11 1 000  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbtnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rd32 = memb ( Rs32 )"   , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbtnew_zomap)) /* mapped to if (Pt4.new) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0011 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbtnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrbtnew_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memh ( #u6 )"    , "1001 1 11 1 010  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhtnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rd32 = memh ( Rs32 )"   , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhtnew_zomap)) /* mapped to if (Pt4.new) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0011 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrhtnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrhtnew_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memub ( #u6 )"   , "1001 1 11 1 001  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubtnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rd32 = memub ( Rs32 )"  , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubtnew_zomap)) /* mapped to if (Pt4.new) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0011 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubtnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrubtnew_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memuh ( #u6 )"   , "1001 1 11 1 011  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhtnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rd32 = memuh ( Rs32 )"  , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhtnew_zomap)) /* mapped to if (Pt4.new) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0011 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadruhtnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadruhtnew_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memw ( #u6 )"    , "1001 1 11 1 100  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadritnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rd32 = memw ( Rs32 )"   , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadritnew_zomap)) /* mapped to if (Pt4.new) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0011 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadritnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadritnew_pi */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rdd32 = memd ( #u6 )"   , "1001 1 11 1 110  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdtnew_abs */
HEXAGON_MAPPING ("if ( Pt4 .new ) Rdd32 = memd ( Rs32 )"  , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdtnew_zomap)) /* mapped to if (Pt4.new) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0011 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdtnew_io */
HEXAGON_OPCODE ("if ( Pt4 .new ) Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrdtnew_pi */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = #s12"                 , "0111 1110 0uu0iiii PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* C2_cmoveit */
HEXAGON_MAPPING ("if ( Pu4 ) Rd32 = Rs32"                 , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrt)) /* mapped to if (Pu4) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = add ( Rs32 , #s8 )"   , "0111 0100 0uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* A2_paddit */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = add ( Rs32 , Rt32 )"  , "1111 1011  0-0sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_paddt */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = and ( Rs32 , Rt32 )"  , "1111 1001  -00sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_pandt */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = aslh ( Rs32 )"        , "0111 0000  000sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_paslht */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = asrh ( Rs32 )"        , "0111 0000  001sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pasrht */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = or ( Rs32 , Rt32 )"   , "1111 1001  -01sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_port */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = sub ( Rt32 , Rs32 )"  , "1111 1011  0-1sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_psubt */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = sxtb ( Rs32 )"        , "0111 0000  101sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_psxtbt */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = sxth ( Rs32 )"        , "0111 0000  111sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_psxtht */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = xor ( Rs32 , Rt32 )"  , "1111 1001  -11sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_pxort */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = zxtb ( Rs32 )"        , "0111 0000  100sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pzxtbt */
HEXAGON_OPCODE ("if ( Pu4 ) Rd32 = zxth ( Rs32 )"        , "0111 0000  110sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pzxtht */
HEXAGON_MAPPING ("if ( Pu4 ) Rdd32 = Rss32"               , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpt)) /* mapped to if (Pu4) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ( Pu4 ) Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* C2_ccombinewt */
HEXAGON_OPCODE ("if ( Pu4 ) call #r15:2"                 , "0101 1101  ii0iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J2_callt */
HEXAGON_OPCODE ("if ( Pu4 ) callr Rs32"                  , "0101 0001  000sssss  PP----uu  --------"    , 0x4, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_CONDEXEC) /* J2_callrt */
HEXAGON_OPCODE ("if ( Pu4 ) jump #r15:2"                 , "0101 1100  ii0iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J2_jumpt */
HEXAGON_OPCODE ("if ( Pu4 ) jumpr Rs32"                  , "0101 0011  010sssss  PP--0-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC) /* J2_jumprt */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = #s12"            , "0111 1110 0uu0iiii PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* C2_cmovenewit */
HEXAGON_MAPPING ("if ( Pu4 .new ) Rd32 = Rs32"            , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrtnew)) /* mapped to if (Pu4.new) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = add ( Rs32 , #s8 )" , "0111 0100 0uusssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* A2_padditnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = add ( Rs32 , Rt32 )" , "1111 1011  0-0sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_paddtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = and ( Rs32 , Rt32 )" , "1111 1001  -00sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_pandtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = aslh ( Rs32 )"   , "0111 0000  000sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_paslhtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = asrh ( Rs32 )"   , "0111 0000  001sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pasrhtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = or ( Rs32 , Rt32 )" , "1111 1001  -01sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_portnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = sub ( Rt32 , Rs32 )" , "1111 1011  0-1sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_psubtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = sxtb ( Rs32 )"   , "0111 0000  101sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_psxtbtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = sxth ( Rs32 )"   , "0111 0000  111sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_psxthtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = xor ( Rs32 , Rt32 )" , "1111 1001  -11sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_pxortnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = zxtb ( Rs32 )"   , "0111 0000  100sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pzxtbtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rd32 = zxth ( Rs32 )"   , "0111 0000  110sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pzxthtnew */
HEXAGON_MAPPING ("if ( Pu4 .new ) Rdd32 = Rss32"          , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrptnew)) /* mapped to if (Pu4.new) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if ( Pu4 .new ) Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* C2_ccombinewnewt */
HEXAGON_OPCODE ("if ( Pu4 .new ) jump:nt #r15:2"         , "0101 1100  ii0iiiii  PPi01-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumptnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) jump:t #r15:2"          , "0101 1100  ii0iiiii  PPi11-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumptnewpt */
HEXAGON_OPCODE ("if ( Pu4 .new ) jumpr:nt Rs32"          , "0101 0011  010sssss  PP-01-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW) /* J2_jumprtnew */
HEXAGON_OPCODE ("if ( Pu4 .new ) jumpr:t Rs32"           , "0101 0011  010sssss  PP-11-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW) /* J2_jumprtnewpt */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 00 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 00 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 00 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 00 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 00 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 00 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 00 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 00 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 00 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 00 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 00 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 00 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 00 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 00 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 00 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 00 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 00 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 00 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 00 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 00 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 00 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 00 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 00 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 00 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( #u6 ) = Nt8 .new"     , "1010 1 11 1 101  ---ii  PP000ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewt_abs */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( #u6 ) = Rt32"         , "1010 1 11 1 000  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbt_abs */
HEXAGON_MAPPING ("if ( Pv4 ) memb ( Rs32 ) = #S6"         , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbt_zomap)) /* mapped to if (Pv4) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 ) memb ( Rs32 ) = Nt8 .new"    , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbnewt_zomap)) /* mapped to if (Pv4) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 ) memb ( Rs32 ) = Rt32"        , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbt_zomap)) /* mapped to if (Pv4) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 00  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirbt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0000 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerbnewt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0000 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerbt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerbnewt_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerbt_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( #u6 ) = Rtt32"        , "1010 1 11 1 110  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdt_abs */
HEXAGON_MAPPING ("if ( Pv4 ) memd ( Rs32 ) = Rtt32"       , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerdt_zomap)) /* mapped to if (Pv4) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0000 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerdt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 00 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 00 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 00 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 00 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerdt_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( #u6 ) = Nt8 .new"     , "1010 1 11 1 101  ---ii  PP001ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewt_abs */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( #u6 ) = Rt32.h"       , "1010 1 11 1 011  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerft_abs */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( #u6 ) = Rt32"         , "1010 1 11 1 010  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerht_abs */
HEXAGON_MAPPING ("if ( Pv4 ) memh ( Rs32 ) = #S6"         , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirht_zomap)) /* mapped to if (Pv4) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 ) memh ( Rs32 ) = Nt8 .new"    , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhnewt_zomap)) /* mapped to if (Pv4) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 ) memh ( Rs32 ) = Rt32.h"      , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerft_zomap)) /* mapped to if (Pv4) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ( Pv4 ) memh ( Rs32 ) = Rt32"        , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerht_zomap)) /* mapped to if (Pv4) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 00  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirht_io */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0000 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerhnewt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0000 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerft_io */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0000 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerht_io */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 00 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 00 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 00 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 00 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerhnewt_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerft_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerht_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( #u6 ) = Nt8 .new"     , "1010 1 11 1 101  ---ii  PP010ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewt_abs */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( #u6 ) = Rt32"         , "1010 1 11 1 100  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerit_abs */
HEXAGON_MAPPING ("if ( Pv4 ) memw ( Rs32 ) = #S6"         , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirit_zomap)) /* mapped to if (Pv4) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 ) memw ( Rs32 ) = Nt8 .new"    , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerinewt_zomap)) /* mapped to if (Pv4) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 ) memw ( Rs32 ) = Rt32"        , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerit_zomap)) /* mapped to if (Pv4) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 00  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirit_io */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0000 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerinewt_io */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0000 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerit_io */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerinewt_pi */
HEXAGON_OPCODE ("if ( Pv4 ) memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerit_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 10 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 10 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 10 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 10 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 10 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 10 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 10 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 10 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 10 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 10 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 10 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 10 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 10 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 10 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 10 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 10 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 10 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 10 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 10 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 10 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 10 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 10 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 10 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 10 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP100ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewtnew_abs */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( #u6 ) = Rt32"    , "1010 1 11 1 000  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbtnew_abs */
HEXAGON_MAPPING ("if ( Pv4 .new ) memb ( Rs32 ) = #S6"    , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbtnew_zomap)) /* mapped to if (Pv4.new) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 .new ) memb ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbnewtnew_zomap)) /* mapped to if (Pv4.new) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 .new ) memb ( Rs32 ) = Rt32"   , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbtnew_zomap)) /* mapped to if (Pv4.new) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 10  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirbtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0010 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbnewtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0010 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerbnewtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerbtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( #u6 ) = Rtt32"   , "1010 1 11 1 110  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdtnew_abs */
HEXAGON_MAPPING ("if ( Pv4 .new ) memd ( Rs32 ) = Rtt32"  , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerdtnew_zomap)) /* mapped to if (Pv4.new) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0010 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerdtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 10 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 10 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 10 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 10 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerdtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP101ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewtnew_abs */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( #u6 ) = Rt32.h"  , "1010 1 11 1 011  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerftnew_abs */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( #u6 ) = Rt32"    , "1010 1 11 1 010  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhtnew_abs */
HEXAGON_MAPPING ("if ( Pv4 .new ) memh ( Rs32 ) = #S6"    , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhtnew_zomap)) /* mapped to if (Pv4.new) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 .new ) memh ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhnewtnew_zomap)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 .new ) memh ( Rs32 ) = Rt32.h" , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerftnew_zomap)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if ( Pv4 .new ) memh ( Rs32 ) = Rt32"   , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhtnew_zomap)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 10  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirhtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0010 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhnewtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0010 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerftnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0010 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 10 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 10 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 10 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 10 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerhnewtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerftnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerhtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( #u6 ) = Nt8 .new" , "1010 1 11 1 101  ---ii  PP110ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewtnew_abs */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( #u6 ) = Rt32"    , "1010 1 11 1 100  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstoreritnew_abs */
HEXAGON_MAPPING ("if ( Pv4 .new ) memw ( Rs32 ) = #S6"    , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeiritnew_zomap)) /* mapped to if (Pv4.new) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if ( Pv4 .new ) memw ( Rs32 ) = Nt8 .new" , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerinewtnew_zomap)) /* mapped to if (Pv4.new) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if ( Pv4 .new ) memw ( Rs32 ) = Rt32"   , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstoreritnew_zomap)) /* mapped to if (Pv4.new) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 10  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeiritnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0010 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerinewtnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0010 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstoreritnew_io */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerinewtnew_pi */
HEXAGON_OPCODE ("if ( Pv4 .new ) memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstoreritnew_pi */
HEXAGON_OPCODE ("if ( Rs32 != #0 ) jump:nt #r13:2"       , "0110 0001  00isssss  PPi0iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprz */
HEXAGON_OPCODE ("if ( Rs32 != #0 ) jump:t #r13:2"        , "0110 0001  00isssss  PPi1iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprzpt */
HEXAGON_OPCODE ("if ( Rs32 <= #0 ) jump:nt #r13:2"       , "0110 0001  11isssss  PPi0iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprltez */
HEXAGON_OPCODE ("if ( Rs32 <= #0 ) jump:t #r13:2"        , "0110 0001  11isssss  PPi1iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprltezpt */
HEXAGON_OPCODE ("if ( Rs32 == #0 ) jump:nt #r13:2"       , "0110 0001  10isssss  PPi0iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprnz */
HEXAGON_OPCODE ("if ( Rs32 == #0 ) jump:t #r13:2"        , "0110 0001  10isssss  PPi1iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprnzpt */
HEXAGON_OPCODE ("if ( Rs32 >= #0 ) jump:nt #r13:2"       , "0110 0001  01isssss  PPi0iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprgtez */
HEXAGON_OPCODE ("if ( Rs32 >= #0 ) jump:t #r13:2"        , "0110 0001  01isssss  PPi1iiii  iiiiiii-"    , 0x8, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_CONDITION_DOTNEW|A_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC) /* J2_jumprgtezpt */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , #-1 ) ) jump:nt #r9:2" , "0010 -1 100  0ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , #-1 ) ) jump:t #r9:2" , "0010 -1 100  0ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 000  0ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 000  0ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 000  0ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.eq ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 000  0ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , #-1 ) ) jump:nt #r9:2" , "0010 -1 101  0ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , #-1 ) ) jump:t #r9:2" , "0010 -1 101  0ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 001  0ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 001  0ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 001  0ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gt ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 001  0ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gt ( Rt32 , Ns8 .new ) ) jump:nt #r9:2" , "0010 -0 011  0ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmplt_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gt ( Rt32 , Ns8 .new ) ) jump:t #r9:2" , "0010 -0 011  0ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmplt_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gtu ( Ns8 .new , #U5 ) ) jump:nt #r9:2" , "0010 -1 010  0ii-sss  PP0IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gtu ( Ns8 .new , #U5 ) ) jump:t #r9:2" , "0010 -1 010  0ii-sss  PP1IIIII  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gtu ( Ns8 .new , Rt32 ) ) jump:nt #r9:2" , "0010 -0 010  0ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gtu ( Ns8 .new , Rt32 ) ) jump:t #r9:2" , "0010 -0 010  0ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_t_jumpnv_t */
HEXAGON_OPCODE ("if ( cmp.gtu ( Rt32 , Ns8 .new ) ) jump:nt #r9:2" , "0010 -0 100  0ii-sss  PP0ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpltu_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( cmp.gtu ( Rt32 , Ns8 .new ) ) jump:t #r9:2" , "0010 -0 100  0ii-sss  PP1ttttt  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_cmpltu_t_jumpnv_t */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; allocframe ( #u5:3 )" , "0111101--110ddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_allocframe */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; dealloc_return"   , "0101101--110ddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrt_SL2_return */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; deallocframe"     , "0101101--110ddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_deallocframe */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( ! p0 ) dealloc_return" , "0101101--110ddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrt_SL2_return_f */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( ! p0 ) jumpr Lr" , "0101101--110ddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_jumpr31_f */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( ! p0 .new ) dealloc_return:nt" , "0101101--110ddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrt_SL2_return_fnew */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( ! p0 .new ) jumpr:nt Lr" , "0101101--110ddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( p0 ) dealloc_return" , "0101101--110ddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrt_SL2_return_t */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( p0 ) jumpr Lr" , "0101101--110ddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_jumpr31_t */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( p0 .new ) dealloc_return:nt" , "0101101--110ddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrt_SL2_return_tnew */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; if ( p0 .new ) jumpr:nt Lr" , "0101101--110ddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; jumpr Lr"         , "0101101--110ddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_jumpr31 */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "0111101--110ddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storebi0 */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "0111101--110ddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storebi1 */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = Rt16" , "0111101--110ddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS1_storeb_io */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "0111101--110ddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_stored_sp */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "0111101--110ddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storeh_io */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "0111101--110ddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storewi0 */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "0111101--110ddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storewi1 */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = Rt16" , "0111101--110ddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS1_storew_io */
HEXAGON_OPCODE ("if ( p0 ) Rd16 = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "0111101--110ddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SS2_storew_sp */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memb ( Rs16 + #u3:0 )" , "0101101--110eeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_loadrb_io */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memh ( Rs16 + #u3:1 )" , "0101101--110eeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_loadrh_io */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memub ( Rs16 + #u4:0 )" , "0101101--110eeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL1_loadrub_io */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0101101--110eeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_loadruh_io */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memw ( Rs16 + #u4:2 )" , "0101101--110eeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL1_loadri_io */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rd16 = memw ( Sp + #u5:2 )" , "0101101--110eeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_loadri_sp */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( #0 , #u2 )" , "0011101--110eeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combine0i */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( #0 , Rs16 )" , "0011101--110eeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combinezr */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( #1 , #u2 )" , "0011101--110eeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combine1i */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( #2 , #u2 )" , "0011101--110eeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combine2i */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( #3 , #u2 )" , "0011101--110eeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combine3i */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = combine ( Rs16 , #0 )" , "0011101--110eeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_combinerz */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; Rdd8 = memd ( Sp + #u5:3 )" , "0101101--110eeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SL2_loadrd_sp */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; if ( ! p0 ) Rd16 = #0" , "0011101--110eeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_clrf */
HEXAGON_OPCODE ("if ( p0 ) Re16 = #0 ; if ( p0 ) Rd16 = #0" , "0011101--110eeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrt_SA1_clrt */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; allocframe ( #u5:3 )" , "0111101--100ddddEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_allocframe */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; dealloc_return" , "0101101--100ddddEE11111101---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrtnew_SL2_return */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; deallocframe" , "0101101--100ddddEE11111100---0--"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_deallocframe */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( ! p0 ) dealloc_return" , "0101101--100ddddEE11111101---101"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrtnew_SL2_return_f */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( ! p0 ) jumpr Lr" , "0101101--100ddddEE11111111---101"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_jumpr31_f */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( ! p0 .new ) dealloc_return:nt" , "0101101--100ddddEE11111101---111"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrtnew_SL2_return_fnew */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( ! p0 .new ) jumpr:nt Lr" , "0101101--100ddddEE11111111---111"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( p0 ) dealloc_return" , "0101101--100ddddEE11111101---100"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrtnew_SL2_return_t */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( p0 ) jumpr Lr" , "0101101--100ddddEE11111111---100"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_jumpr31_t */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( p0 .new ) dealloc_return:nt" , "0101101--100ddddEE11111101---110"           , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_clrtnew_SL2_return_tnew */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; if ( p0 .new ) jumpr:nt Lr" , "0101101--100ddddEE11111111---110"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; jumpr Lr"    , "0101101--100ddddEE11111111---0--"           , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_jumpr31 */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "0111101--100ddddEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storebi0 */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "0111101--100ddddEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storebi1 */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memb ( Rs16 + #u4:0 ) = Rt16" , "0111101--100ddddEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS1_storeb_io */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "0111101--100ddddEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_stored_sp */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "0111101--100ddddEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storeh_io */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "0111101--100ddddEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storewi0 */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "0111101--100ddddEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storewi1 */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memw ( Rs16 + #u4:2 ) = Rt16" , "0111101--100ddddEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS1_storew_io */
HEXAGON_OPCODE ("if ( p0 .new ) Rd16 = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "0111101--100ddddEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SS2_storew_sp */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memb ( Rs16 + #u3:0 )" , "0101101--100eeeeEE110iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_loadrb_io */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memh ( Rs16 + #u3:1 )" , "0101101--100eeeeEE100iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_loadrh_io */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memub ( Rs16 + #u4:0 )" , "0101101--100eeeeEE01iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL1_loadrub_io */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memuh ( Rs16 + #u3:1 )" , "0101101--100eeeeEE101iiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_loadruh_io */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memw ( Rs16 + #u4:2 )" , "0101101--100eeeeEE00iiiissssdddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL1_loadri_io */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rd16 = memw ( Sp + #u5:2 )" , "0101101--100eeeeEE11110iiiiidddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_loadri_sp */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( #0 , #u2 )" , "0011101--100eeeeEE1111-0-ii00ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combine0i */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( #0 , Rs16 )" , "0011101--100eeeeEE1111-1ssss0ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combinezr */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( #1 , #u2 )" , "0011101--100eeeeEE1111-0-ii01ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combine1i */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( #2 , #u2 )" , "0011101--100eeeeEE1111-0-ii10ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combine2i */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( #3 , #u2 )" , "0011101--100eeeeEE1111-0-ii11ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combine3i */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = combine ( Rs16 , #0 )" , "0011101--100eeeeEE1111-1ssss1ddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_combinerz */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; Rdd8 = memd ( Sp + #u5:3 )" , "0101101--100eeeeEE111110iiiiiddd"           , 0x1, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SL2_loadrd_sp */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; if ( ! p0 ) Rd16 = #0" , "0011101--100eeeeEE11101--111dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_clrf */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; if ( ! p0 .new ) Rd16 = #0" , "0011101--100eeeeEE11101--101dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_clrfnew */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; if ( p0 ) Rd16 = #0" , "0011101--100eeeeEE11101--110dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_clrt */
HEXAGON_OPCODE ("if ( p0 .new ) Re16 = #0 ; if ( p0 .new ) Rd16 = #0" , "0011101--100eeeeEE11101--100dddd"           , 0x1, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_clrtnew_SA1_clrtnew */
HEXAGON_OPCODE ("if ( tstbit ( Ns8 .new , #0 ) ) jump:nt #r9:2" , "0010 -1 011  0ii-sss  PP0-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_t_jumpnv_nt */
HEXAGON_OPCODE ("if ( tstbit ( Ns8 .new , #0 ) ) jump:t #r9:2" , "0010 -1 011  0ii-sss  PP1-----  iiiiiii-"   , 0x1, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_MEMORY|A_RESTRICT_SLOT1_NOSTORE|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_t_jumpnv_t */
HEXAGON_OPCODE ("if Ps4 .new dealloc_return:nt"          , "1001 011 0 000 11110 PP0010ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_tnew_pnt_alt */
HEXAGON_OPCODE ("if Ps4 .new dealloc_return:t"           , "1001 011 0 000 11110 PP0110ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_DEALLOCRET) /* L4_return_tnew_pt_alt */
HEXAGON_OPCODE ("if Ps4 dealloc_return"                  , "1001 011 0 000 11110 PP0100ss ---11110"     , 0x1, 0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_DEALLOCRET) /* L4_return_t_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memb ( #u6 )"        , "1001 1 11 1 000  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbtnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rd32 = memb ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbtnew_zomap_alt)) /* mapped to if (Pt4.new) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memb ( Rs32 + #u6:0 )" , "0100 0011 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbtnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memb ( Rz32 ++ #s4:0 )" , "1001 1 01 1 000  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrbtnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memh ( #u6 )"        , "1001 1 11 1 010  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrhtnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rd32 = memh ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrhtnew_zomap_alt)) /* mapped to if (Pt4.new) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memh ( Rs32 + #u6:1 )" , "0100 0011 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrhtnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 010  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrhtnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memub ( #u6 )"       , "1001 1 11 1 001  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubtnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rd32 = memub ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubtnew_zomap_alt)) /* mapped to if (Pt4.new) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memub ( Rs32 + #u6:0 )" , "0100 0011 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubtnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memub ( Rz32 ++ #s4:0 )" , "1001 1 01 1 001  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrubtnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memuh ( #u6 )"       , "1001 1 11 1 011  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruhtnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rd32 = memuh ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruhtnew_zomap_alt)) /* mapped to if (Pt4.new) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memuh ( Rs32 + #u6:1 )" , "0100 0011 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadruhtnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memuh ( Rz32 ++ #s4:1 )" , "1001 1 01 1 011  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadruhtnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memw ( #u6 )"        , "1001 1 11 1 100  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadritnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rd32 = memw ( Rs32 )"       , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadritnew_zomap_alt)) /* mapped to if (Pt4.new) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memw ( Rs32 + #u6:2 )" , "0100 0011 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadritnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rd32 = memw ( Rz32 ++ #s4:2 )" , "1001 1 01 1 100  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadritnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 .new Rdd32 = memd ( #u6 )"       , "1001 1 11 1 110  iiiii  PP110tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdtnew_abs_alt */
HEXAGON_MAPPING ("if Pt4 .new Rdd32 = memd ( Rs32 )"      , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdtnew_zomap_alt)) /* mapped to if (Pt4.new) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 .new Rdd32 = memd ( Rs32 + #u6:3 )" , "0100 0011 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdtnew_io_alt */
HEXAGON_OPCODE ("if Pt4 .new Rdd32 = memd ( Rz32 ++ #s4:3 )" , "1001 1 01 1 110  zzzzz  PP110tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L2_ploadrdtnew_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memb ( #u6 )"             , "1001 1 11 1 000  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrbt_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rd32 = memb ( Rs32 )"            , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrbt_zomap_alt)) /* mapped to if (Pt4) Rd32=memb(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rd32 = memb ( Rs32 + #u6:0 )"    , "0100 0001 000  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrbt_io_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memb ( Rz32 ++ #s4:0 )"   , "1001 1 01 1 000  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrbt_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memh ( #u6 )"             , "1001 1 11 1 010  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrht_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rd32 = memh ( Rs32 )"            , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrht_zomap_alt)) /* mapped to if (Pt4) Rd32=memh(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rd32 = memh ( Rs32 + #u6:1 )"    , "0100 0001 010  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrht_io_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memh ( Rz32 ++ #s4:1 )"   , "1001 1 01 1 010  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrht_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memub ( #u6 )"            , "1001 1 11 1 001  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrubt_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rd32 = memub ( Rs32 )"           , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrubt_zomap_alt)) /* mapped to if (Pt4) Rd32=memub(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rd32 = memub ( Rs32 + #u6:0 )"   , "0100 0001 001  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrubt_io_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memub ( Rz32 ++ #s4:0 )"  , "1001 1 01 1 001  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrubt_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memuh ( #u6 )"            , "1001 1 11 1 011  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadruht_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rd32 = memuh ( Rs32 )"           , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadruht_zomap_alt)) /* mapped to if (Pt4) Rd32=memuh(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rd32 = memuh ( Rs32 + #u6:1 )"   , "0100 0001 011  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadruht_io_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memuh ( Rz32 ++ #s4:1 )"  , "1001 1 01 1 011  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadruht_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memw ( #u6 )"             , "1001 1 11 1 100  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrit_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rd32 = memw ( Rs32 )"            , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrit_zomap_alt)) /* mapped to if (Pt4) Rd32=memw(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rd32 = memw ( Rs32 + #u6:2 )"    , "0100 0001 100  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrit_io_alt */
HEXAGON_OPCODE ("if Pt4 Rd32 = memw ( Rz32 ++ #s4:2 )"   , "1001 1 01 1 100  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrit_pi_alt */
HEXAGON_OPCODE ("if Pt4 Rdd32 = memd ( #u6 )"            , "1001 1 11 1 110  iiiii  PP100tti  1--ddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* L4_ploadrdt_abs_alt */
HEXAGON_MAPPING ("if Pt4 Rdd32 = memd ( Rs32 )"           , "0000ttdddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(L2_ploadrdt_zomap_alt)) /* mapped to if (Pt4) Rdd32=memd(Rs32+#0) */
HEXAGON_OPCODE ("if Pt4 Rdd32 = memd ( Rs32 + #u6:3 )"   , "0100 0001 110  sssss  PP0ttiii  iiiddddd"   , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* L2_ploadrdt_io_alt */
HEXAGON_OPCODE ("if Pt4 Rdd32 = memd ( Rz32 ++ #s4:3 )"  , "1001 1 01 1 110  zzzzz  PP100tti  iiiddddd" , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L2_ploadrdt_pi_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = #s12"                , "0111 1110 0uu0iiii PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* C2_cmovenewit_alt */
HEXAGON_MAPPING ("if Pu4 .new Rd32 = Rs32"                , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrtnew_alt)) /* mapped to if (Pu4.new) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = add ( Rs32 , #s8 )"  , "0111 0100 0uusssss PP1iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* A2_padditnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = add ( Rs32 , Rt32 )" , "1111 1011  0-0sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_paddtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = and ( Rs32 , Rt32 )" , "1111 1001  -00sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_pandtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = aslh ( Rs32 )"       , "0111 0000  000sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_paslhtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = asrh ( Rs32 )"       , "0111 0000  001sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pasrhtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = or ( Rs32 , Rt32 )"  , "1111 1001  -01sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_portnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = sub ( Rt32 , Rs32 )" , "1111 1011  0-1sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_psubtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = sxtb ( Rs32 )"       , "0111 0000  101sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_psxtbtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = sxth ( Rs32 )"       , "0111 0000  111sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_psxthtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = xor ( Rs32 , Rt32 )" , "1111 1001  -11sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A2_pxortnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = zxtb ( Rs32 )"       , "0111 0000  100sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pzxtbtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new Rd32 = zxth ( Rs32 )"       , "0111 0000  110sssss  PP1-01uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* A4_pzxthtnew_alt */
HEXAGON_MAPPING ("if Pu4 .new Rdd32 = Rss32"              , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrptnew_alt)) /* mapped to if (Pu4.new) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if Pu4 .new Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP1ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC|A_CONDITION_DOTNEW) /* C2_ccombinewnewt_alt */
HEXAGON_OPCODE ("if Pu4 .new jump:nt #r15:2"             , "0101 1100  ii0iiiii  PPi01-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumptnew_alt */
HEXAGON_OPCODE ("if Pu4 .new jump:t #r15:2"              , "0101 1100  ii0iiiii  PPi11-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* J2_jumptnewpt_alt */
HEXAGON_OPCODE ("if Pu4 .new jumpr:nt Rs32"              , "0101 0011  010sssss  PP-01-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW) /* J2_jumprtnew_alt */
HEXAGON_OPCODE ("if Pu4 .new jumpr:t Rs32"               , "0101 0011  010sssss  PP-11-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW) /* J2_jumprtnewpt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = #s12"                     , "0111 1110 0uu0iiii PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* C2_cmoveit_alt */
HEXAGON_MAPPING ("if Pu4 Rd32 = Rs32"                     , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrt_alt)) /* mapped to if (Pu4) Rd32=add(Rs32,#0) */
HEXAGON_OPCODE ("if Pu4 Rd32 = add ( Rs32 , #s8 )"       , "0111 0100 0uusssss PP0iiiii iiiddddd"       , 0xf, 0, 0|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* A2_paddit_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = add ( Rs32 , Rt32 )"      , "1111 1011  0-0sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_paddt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = and ( Rs32 , Rt32 )"      , "1111 1001  -00sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_pandt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = aslh ( Rs32 )"            , "0111 0000  000sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_paslht_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = asrh ( Rs32 )"            , "0111 0000  001sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pasrht_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = or ( Rs32 , Rt32 )"       , "1111 1001  -01sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_port_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = sub ( Rt32 , Rs32 )"      , "1111 1011  0-1sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_psubt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = sxtb ( Rs32 )"            , "0111 0000  101sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_psxtbt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = sxth ( Rs32 )"            , "0111 0000  111sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_psxtht_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = xor ( Rs32 , Rt32 )"      , "1111 1001  -11sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A2_pxort_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = zxtb ( Rs32 )"            , "0111 0000  100sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pzxtbt_alt */
HEXAGON_OPCODE ("if Pu4 Rd32 = zxth ( Rs32 )"            , "0111 0000  110sssss  PP1-00uu ---ddddd"     , 0xf, 0, 0|A_CONDEXEC) /* A4_pzxtht_alt */
HEXAGON_MAPPING ("if Pu4 Rdd32 = Rss32"                   , "0000uudddddsssss0000000000000000"           , HEXAGON_MAP_FNAME(A2_tfrpt_alt)) /* mapped to if (Pu4) Rdd32=combine(Rss.H32,Rss.L32) */
HEXAGON_OPCODE ("if Pu4 Rdd32 = combine ( Rs32 , Rt32 )" , "1111 1101  ---sssss  PP0ttttt 0uuddddd"     , 0xf, 0, 0|A_CONDEXEC) /* C2_ccombinewt_alt */
HEXAGON_OPCODE ("if Pu4 call #r15:2"                     , "0101 1101  ii0iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J2_callt_alt */
HEXAGON_OPCODE ("if Pu4 callr Rs32"                      , "0101 0001  000sssss  PP----uu  --------"    , 0x4, 0|IMPLICIT_PC|IMPLICIT_LR, 0|A_BRANCH|A_CONDEXEC) /* J2_callrt_alt */
HEXAGON_OPCODE ("if Pu4 jump #r15:2"                     , "0101 1100  ii0iiiii  PPi-0-uu  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* J2_jumpt_alt */
HEXAGON_OPCODE ("if Pu4 jumpr Rs32"                      , "0101 0011  010sssss  PP--0-uu  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC) /* J2_jumprt_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 10 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 10 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 10 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 10 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrbtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 10 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 10 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 10 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 10 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrhtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 10 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 10 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 10 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 10 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrubtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 10 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 10 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 10 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 10 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadruhtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 10 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 10 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 10 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 10 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadritnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 10 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 10 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 10 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 10 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* L4_ploadrdtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( #u6 ) = Nt8 .new"    , "1010 1 11 1 101  ---ii  PP100ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewtnew_abs_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( #u6 ) = Rt32"        , "1010 1 11 1 000  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbtnew_abs_alt */
HEXAGON_MAPPING ("if Pv4 .new memb ( Rs32 ) = #S6"        , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbtnew_zomap_alt)) /* mapped to if (Pv4.new) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 .new memb ( Rs32 ) = Nt8 .new"   , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbnewtnew_zomap_alt)) /* mapped to if (Pv4.new) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 .new memb ( Rs32 ) = Rt32"       , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerbtnew_zomap_alt)) /* mapped to if (Pv4.new) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + #u6:0 ) = #S6" , "0011 100 10  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirbtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0010 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbnewtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + #u6:0 ) = Rt32" , "0100 0010 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerbtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbnewtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerbtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerbnewtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memb ( Rz32 ++ #s4:0 ) = Rt32" , "1010 1 01 1 000  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerbtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( #u6 ) = Rtt32"       , "1010 1 11 1 110  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdtnew_abs_alt */
HEXAGON_MAPPING ("if Pv4 .new memd ( Rs32 ) = Rtt32"      , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerdtnew_zomap_alt)) /* mapped to if (Pv4.new) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rs32 + #u6:3 ) = Rtt32" , "0100 0010 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerdtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 10 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 10 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 10 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 10 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerdtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memd ( Rz32 ++ #s4:3 ) = Rtt32" , "1010 1 01 1 110  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerdtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( #u6 ) = Nt8 .new"    , "1010 1 11 1 101  ---ii  PP101ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewtnew_abs_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( #u6 ) = Rt32.h"      , "1010 1 11 1 011  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerftnew_abs_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( #u6 ) = Rt32"        , "1010 1 11 1 010  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhtnew_abs_alt */
HEXAGON_MAPPING ("if Pv4 .new memh ( Rs32 ) = #S6"        , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirhtnew_zomap_alt)) /* mapped to if (Pv4.new) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 .new memh ( Rs32 ) = Nt8 .new"   , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhnewtnew_zomap_alt)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 .new memh ( Rs32 ) = Rt32.h"     , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerftnew_zomap_alt)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if Pv4 .new memh ( Rs32 ) = Rt32"       , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerhtnew_zomap_alt)) /* mapped to if (Pv4.new) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + #u6:1 ) = #S6" , "0011 100 10  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeirhtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0010 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhnewtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + #u6:1 ) = Rt32.h" , "0100 0010 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerftnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + #u6:1 ) = Rt32" , "0100 0010 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerhtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 10 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 10 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 10 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhnewtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 10 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerftnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerhtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerhnewtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerftnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memh ( Rz32 ++ #s4:1 ) = Rt32" , "1010 1 01 1 010  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerhtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( #u6 ) = Nt8 .new"    , "1010 1 11 1 101  ---ii  PP110ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewtnew_abs_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( #u6 ) = Rt32"        , "1010 1 11 1 100  ---ii  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstoreritnew_abs_alt */
HEXAGON_MAPPING ("if Pv4 .new memw ( Rs32 ) = #S6"        , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeiritnew_zomap_alt)) /* mapped to if (Pv4.new) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 .new memw ( Rs32 ) = Nt8 .new"   , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S4_pstorerinewtnew_zomap_alt)) /* mapped to if (Pv4.new) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 .new memw ( Rs32 ) = Rt32"       , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S4_pstoreritnew_zomap_alt)) /* mapped to if (Pv4.new) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + #u6:2 ) = #S6" , "0011 100 10  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_UPPERCASE) /* S4_storeiritnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0010 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstorerinewtnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + #u6:2 ) = Rt32" , "0100 0010 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_EXTENDABLE_LOWERCASE) /* S4_pstoreritnew_io_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 10 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 10 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 10 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 10 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 10 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstorerinewtnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 10 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S4_pstoreritnew_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstorerinewtnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 .new memw ( Rz32 ++ #s4:2 ) = Rt32" , "1010 1 01 1 100  zzzzz  PP1ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW) /* S2_pstoreritnew_pi_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memb ( Rs32 + Rt32 << #0 )" , "0011 00 00 000  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memb ( Rs32 + Rt32 << #1 )" , "0011 00 00 000  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memb ( Rs32 + Rt32 << #2 )" , "0011 00 00 000  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memb ( Rs32 + Rt32 << #3 )" , "0011 00 00 000  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrbt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memh ( Rs32 + Rt32 << #0 )" , "0011 00 00 010  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memh ( Rs32 + Rt32 << #1 )" , "0011 00 00 010  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memh ( Rs32 + Rt32 << #2 )" , "0011 00 00 010  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memh ( Rs32 + Rt32 << #3 )" , "0011 00 00 010  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrht_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memub ( Rs32 + Rt32 << #0 )" , "0011 00 00 001  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memub ( Rs32 + Rt32 << #1 )" , "0011 00 00 001  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memub ( Rs32 + Rt32 << #2 )" , "0011 00 00 001  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memub ( Rs32 + Rt32 << #3 )" , "0011 00 00 001  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrubt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memuh ( Rs32 + Rt32 << #0 )" , "0011 00 00 011  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memuh ( Rs32 + Rt32 << #1 )" , "0011 00 00 011  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memuh ( Rs32 + Rt32 << #2 )" , "0011 00 00 011  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memuh ( Rs32 + Rt32 << #3 )" , "0011 00 00 011  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadruht_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memw ( Rs32 + Rt32 << #0 )" , "0011 00 00 100  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memw ( Rs32 + Rt32 << #1 )" , "0011 00 00 100  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memw ( Rs32 + Rt32 << #2 )" , "0011 00 00 100  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rd32 = memw ( Rs32 + Rt32 << #3 )" , "0011 00 00 100  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrit_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 Rdd32 = memd ( Rs32 + Rt32 << #0 )" , "0011 00 00 110  sssss  PP0ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 Rdd32 = memd ( Rs32 + Rt32 << #1 )" , "0011 00 00 110  sssss  PP0ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 Rdd32 = memd ( Rs32 + Rt32 << #2 )" , "0011 00 00 110  sssss  PP1ttttt  0vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 Rdd32 = memd ( Rs32 + Rt32 << #3 )" , "0011 00 00 110  sssss  PP1ttttt  1vvddddd"  , 0x3, 0, 0|A_MEMORY|A_CONDEXEC) /* L4_ploadrdt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memb ( #u6 ) = Nt8 .new"         , "1010 1 11 1 101  ---ii  PP000ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbnewt_abs_alt */
HEXAGON_OPCODE ("if Pv4 memb ( #u6 ) = Rt32"             , "1010 1 11 1 000  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerbt_abs_alt */
HEXAGON_MAPPING ("if Pv4 memb ( Rs32 ) = #S6"             , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirbt_zomap_alt)) /* mapped to if (Pv4) memb(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 memb ( Rs32 ) = Nt8 .new"        , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbnewt_zomap_alt)) /* mapped to if (Pv4) memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 memb ( Rs32 ) = Rt32"            , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerbt_zomap_alt)) /* mapped to if (Pv4) memb(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + #u6:0 ) = #S6"     , "0011 100 00  00  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirbt_io_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + #u6:0 ) = Nt8 .new" , "0100 0000 101  sssss  PPi00ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerbnewt_io_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + #u6:0 ) = Rt32"    , "0100 0000 000  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerbt_io_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 000  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 000  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 000  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv00ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbnewt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 000  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerbt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rz32 ++ #s4:0 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP100ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerbnewt_pi_alt */
HEXAGON_OPCODE ("if Pv4 memb ( Rz32 ++ #s4:0 ) = Rt32"   , "1010 1 01 1 000  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerbt_pi_alt */
HEXAGON_OPCODE ("if Pv4 memd ( #u6 ) = Rtt32"            , "1010 1 11 1 110  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerdt_abs_alt */
HEXAGON_MAPPING ("if Pv4 memd ( Rs32 ) = Rtt32"           , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerdt_zomap_alt)) /* mapped to if (Pv4) memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("if Pv4 memd ( Rs32 + #u6:3 ) = Rtt32"   , "0100 0000 110  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerdt_io_alt */
HEXAGON_OPCODE ("if Pv4 memd ( Rs32 + Ru32 << #0 ) = Rtt32" , "0011 01 00 110  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memd ( Rs32 + Ru32 << #1 ) = Rtt32" , "0011 01 00 110  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memd ( Rs32 + Ru32 << #2 ) = Rtt32" , "0011 01 00 110  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memd ( Rs32 + Ru32 << #3 ) = Rtt32" , "0011 01 00 110  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerdt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memd ( Rz32 ++ #s4:3 ) = Rtt32"  , "1010 1 01 1 110  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerdt_pi_alt */
HEXAGON_OPCODE ("if Pv4 memh ( #u6 ) = Nt8 .new"         , "1010 1 11 1 101  ---ii  PP001ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerhnewt_abs_alt */
HEXAGON_OPCODE ("if Pv4 memh ( #u6 ) = Rt32.h"           , "1010 1 11 1 011  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerft_abs_alt */
HEXAGON_OPCODE ("if Pv4 memh ( #u6 ) = Rt32"             , "1010 1 11 1 010  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerht_abs_alt */
HEXAGON_MAPPING ("if Pv4 memh ( Rs32 ) = #S6"             , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirht_zomap_alt)) /* mapped to if (Pv4) memh(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 memh ( Rs32 ) = Nt8 .new"        , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerhnewt_zomap_alt)) /* mapped to if (Pv4) memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 memh ( Rs32 ) = Rt32.h"          , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerft_zomap_alt)) /* mapped to if (Pv4) memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("if Pv4 memh ( Rs32 ) = Rt32"            , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerht_zomap_alt)) /* mapped to if (Pv4) memh(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + #u6:1 ) = #S6"     , "0011 100 00  01  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirht_io_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + #u6:1 ) = Nt8 .new" , "0100 0000 101  sssss  PPi01ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerhnewt_io_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + #u6:1 ) = Rt32.h"  , "0100 0000 011  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerft_io_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + #u6:1 ) = Rt32"    , "0100 0000 010  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerht_io_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #0 ) = Rt32.h" , "0011 01 00 011  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 010  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #1 ) = Rt32.h" , "0011 01 00 011  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 010  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #2 ) = Rt32.h" , "0011 01 00 011  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 010  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv01ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerhnewt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #3 ) = Rt32.h" , "0011 01 00 011  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerft_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 010  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerht_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rz32 ++ #s4:1 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP101ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerhnewt_pi_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rz32 ++ #s4:1 ) = Rt32.h" , "1010 1 01 1 011  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerft_pi_alt */
HEXAGON_OPCODE ("if Pv4 memh ( Rz32 ++ #s4:1 ) = Rt32"   , "1010 1 01 1 010  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerht_pi_alt */
HEXAGON_OPCODE ("if Pv4 memw ( #u6 ) = Nt8 .new"         , "1010 1 11 1 101  ---ii  PP010ttt  1iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerinewt_abs_alt */
HEXAGON_OPCODE ("if Pv4 memw ( #u6 ) = Rt32"             , "1010 1 11 1 100  ---ii  PP0ttttt  1iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE|A_MUST_EXTEND) /* S4_pstorerit_abs_alt */
HEXAGON_MAPPING ("if Pv4 memw ( Rs32 ) = #S6"             , "0000IIIIIIvvsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirit_zomap_alt)) /* mapped to if (Pv4) memw(Rs32+#0)=#S6 */
HEXAGON_MAPPING ("if Pv4 memw ( Rs32 ) = Nt8 .new"        , "0000tttvvsssss000000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerinewt_zomap_alt)) /* mapped to if (Pv4) memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("if Pv4 memw ( Rs32 ) = Rt32"            , "0000vvsssssttttt0000000000000000"           , HEXAGON_MAP_FNAME(S2_pstorerit_zomap_alt)) /* mapped to if (Pv4) memw(Rs32+#0)=Rt32 */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + #u6:2 ) = #S6"     , "0011 100 00  10  sssss  PPIiiiii  ivvIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE) /* S4_storeirit_io_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + #u6:2 ) = Nt8 .new" , "0100 0000 101  sssss  PPi10ttt  iiiii0vv"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerinewt_io_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + #u6:2 ) = Rt32"    , "0100 0000 100  sssss  PPittttt  iiiii0vv"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_pstorerit_io_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #0 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #0 ) = Rt32" , "0011 01 00 100  sssss  PP0uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_0_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #1 ) = Nt8 .new" , "0011 01 00 101  sssss  PP0uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #1 ) = Rt32" , "0011 01 00 100  sssss  PP0uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_1_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #2 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  0vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #2 ) = Rt32" , "0011 01 00 100  sssss  PP1uuuuu  0vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_2_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #3 ) = Nt8 .new" , "0011 01 00 101  sssss  PP1uuuuu  1vv10ttt"  , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerinewt_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rs32 + Ru32 << #3 ) = Rt32" , "0011 01 00 100  sssss  PP1uuuuu  1vvttttt"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S4_pstorerit_rr_expand_shamt_3_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rz32 ++ #s4:2 ) = Nt8 .new" , "1010 1 01 1 101  zzzzz  PP110ttt  0iiii0vv" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerinewt_pi_alt */
HEXAGON_OPCODE ("if Pv4 memw ( Rz32 ++ #s4:2 ) = Rt32"   , "1010 1 01 1 100  zzzzz  PP1ttttt  0iiii0vv" , 0x3, 0, 0|A_STORE|A_MEMORY|A_CONDEXEC) /* S2_pstorerit_pi_alt */
HEXAGON_OPCODE ("immext ( #u26:6 )"                      , "0000iiii iiiiiiii PPiiiiii iiiiiiii"        , 0xf, 0, 0|A_EXTENDER) /* A4_ext */
HEXAGON_OPCODE ("isync"                                  , "0101 0111  11000000  PP0---00  00000010"    , 0x4, 0, 0|A_SOLO) /* Y2_isync */
HEXAGON_OPCODE ("jump #r22:2"                            , "0101 100i  iiiiiiii  PPiiiiii  iiiiiii-"    , 0xc, 0|IMPLICIT_PC, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_EXTENDABLE_LOWERCASE) /* J2_jump */
HEXAGON_OPCODE ("jumpr Rs32"                             , "0101 0010  100sssss  PP------  --------"    , 0x4, 0|IMPLICIT_PC, 0|A_BRANCH) /* J2_jumpr */
HEXAGON_OPCODE ("k0lock"                                 , "0110 1100 001----- PP------ 011-----"       , 0x8, 0, 0|A_SOLO) /* Y2_k0lock */
HEXAGON_OPCODE ("k0unlock"                               , "0110 1100 001----- PP------ 100-----"       , 0x8, 0, 0|A_SOLO) /* Y2_k0unlock */
HEXAGON_OPCODE ("l2cleanidx ( Rs32 )"                    , "1010 011 00 01sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y5_l2cleanidx */
HEXAGON_OPCODE ("l2cleaninvidx ( Rs32 )"                 , "1010 100 00 11sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y2_l2cleaninvidx */
HEXAGON_OPCODE ("l2fetch ( Rs32 , Rt32 )"                , "1010 011 00 00sssss PP-ttttt --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y4_l2fetch */
HEXAGON_OPCODE ("l2fetch ( Rs32 , Rtt32 )"               , "1010 011 01 00sssss PP-ttttt --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y5_l2fetch */
HEXAGON_OPCODE ("l2invidx ( Rs32 )"                      , "1010 011 00 10sssss PP------ --------"      , 0x1, 0, 0|A_RESTRICT_AX|A_MEMORY) /* Y5_l2invidx */
HEXAGON_OPCODE ("l2kill"                                 , "1010 100 00 01----- PP-00--- --------"      , 0x1, 0, 0|A_SOLO) /* Y2_l2kill */
HEXAGON_OPCODE ("l2tagw ( Rs32 , Rt32 )"                 , "1010 010 00 10sssss PP0ttttt --------"      , 0x1, 0, 0|A_SOLO) /* Y4_l2tagw */
HEXAGON_OPCODE ("loop0 ( #r7:2 , #U10 )"                 , "0110 1001  000IIIII  PP-iiiii  IIIii-II"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF, 0|A_PCREL_BRANCH|A_HWLOOP|A_EXTENDABLE_LOWERCASE) /* J2_loop0i */
HEXAGON_OPCODE ("loop0 ( #r7:2 , Rs32 )"                 , "0110 0000  000sssss  PP-iiiii  ---ii---"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF, 0|A_PCREL_BRANCH|A_HWLOOP|A_EXTENDABLE_LOWERCASE) /* J2_loop0r */
HEXAGON_OPCODE ("loop1 ( #r7:2 , #U10 )"                 , "0110 1001  001IIIII  PP-iiiii  IIIii-II"    , 0x8, 0|IMPLICIT_LC1|IMPLICIT_SA1, 0|A_PCREL_BRANCH|A_HWLOOP|A_DUALJUMP_1|A_DUALJUMP_2|A_EXTENDABLE_LOWERCASE) /* J2_loop1i */
HEXAGON_OPCODE ("loop1 ( #r7:2 , Rs32 )"                 , "0110 0000  001sssss  PP-iiiii  ---ii---"    , 0x8, 0|IMPLICIT_LC1|IMPLICIT_SA1, 0|A_PCREL_BRANCH|A_HWLOOP|A_DUALJUMP_1|A_DUALJUMP_2|A_EXTENDABLE_LOWERCASE) /* J2_loop1r */
HEXAGON_OPCODE ("memb ( #g16:0 ) = Nt8 .new"             , "0100 1ii0 101  iiiii  PPi00ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerbnewgp */
HEXAGON_OPCODE ("memb ( #g16:0 ) = Rt32"                 , "0100 1ii0 000  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerbgp */
HEXAGON_OPCODE ("memb ( gp + #u16:0 ) = Nt8 .new"        , "0100 1ii0 101  iiiii  PPi00ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerbnewgp */
HEXAGON_OPCODE ("memb ( gp + #u16:0 ) = Rt32"            , "0100 1ii0 000  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerbgp */
HEXAGON_OPCODE ("memb ( Rf32 = #U6 ) = Nt8 .new"         , "1010 1 01 1 101  fffff  PP000ttt  1-IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerbnew_ap */
HEXAGON_OPCODE ("memb ( Rf32 = #U6 ) = Rt32"             , "1010 1 01 1 000  fffff  PP0ttttt  1-IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerb_ap */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #0 ; allocframe ( #u5:3 )" , "11110010ssssIIIIEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_allocframe */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "11110010ssssIIIIEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_stored_sp */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "11110010ssssIIIIEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storew_sp */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #1 ; allocframe ( #u5:3 )" , "11110011ssssIIIIEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_allocframe */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #1 ; memd ( Sp + #s6:3 ) = Rtt8" , "11110011ssssIIIIEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_stored_sp */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = #1 ; memw ( Sp + #u5:2 ) = Rt16" , "11110011ssssIIIIEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storew_sp */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = Rt16 ; allocframe ( #u5:3 )" , "1011IIIIssssttttEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_allocframe */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = Rv16 ; memd ( Sp + #s6:3 ) = Rtt8" , "1011IIIIssssvvvvEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_stored_sp */
HEXAGON_OPCODE ("memb ( Rs16 + #U4:0 ) = Rv16 ; memw ( Sp + #u5:2 ) = Rt16" , "1011IIIIssssvvvvEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storew_sp */
HEXAGON_MAPPING ("memb ( Rs32 ) &= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_and_memopb_zomap)) /* mapped to memb(Rs32+#0)&=Rt32 */
HEXAGON_MAPPING ("memb ( Rs32 ) += #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iadd_memopb_zomap)) /* mapped to memb(Rs32+#0)+=#U5 */
HEXAGON_MAPPING ("memb ( Rs32 ) += Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_add_memopb_zomap)) /* mapped to memb(Rs32+#0)+=Rt32 */
HEXAGON_MAPPING ("memb ( Rs32 ) -= #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_isub_memopb_zomap)) /* mapped to memb(Rs32+#0)-=#U5 */
HEXAGON_MAPPING ("memb ( Rs32 ) -= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_sub_memopb_zomap)) /* mapped to memb(Rs32+#0)-=Rt32 */
HEXAGON_MAPPING ("memb ( Rs32 ) = #S8"                    , "0000IIIIIIIIsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirb_zomap)) /* mapped to memb(Rs32+#0)=#S8 */
HEXAGON_MAPPING ("memb ( Rs32 ) = Nt8 .new"               , "0000tttsssss00000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerbnew_zomap)) /* mapped to memb(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("memb ( Rs32 ) = Rt32"                   , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerb_zomap)) /* mapped to memb(Rs32+#0)=Rt32 */
HEXAGON_MAPPING ("memb ( Rs32 ) = clrbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iand_memopb_zomap)) /* mapped to memb(Rs32+#0)=clrbit(#U5) */
HEXAGON_MAPPING ("memb ( Rs32 ) = setbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_ior_memopb_zomap)) /* mapped to memb(Rs32+#0)=setbit(#U5) */
HEXAGON_MAPPING ("memb ( Rs32 ) |= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_or_memopb_zomap)) /* mapped to memb(Rs32+#0)|=Rt32 */
HEXAGON_OPCODE ("memb ( Rs32 + #s11:0 ) = Nt8 .new"      , "1010 0 ii 1 101  sssss  PPi00ttt  iiiiiiii" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerbnew_io */
HEXAGON_OPCODE ("memb ( Rs32 + #s11:0 ) = Rt32"          , "1010 0 ii 1 000  sssss  PPittttt  iiiiiiii" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) &= Rt32"          , "0011 111 0- 00sssss  PP0iiiii  i10ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_and_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) += #U5"           , "0011 111 1- 00sssss  PP0iiiii  i00IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iadd_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) += Rt32"          , "0011 111 0- 00sssss  PP0iiiii  i00ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_add_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) -= #U5"           , "0011 111 1- 00sssss  PP0iiiii  i01IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_isub_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) -= Rt32"          , "0011 111 0- 00sssss  PP0iiiii  i01ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_sub_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) = #S8"            , "0011 110 -- 00  sssss  PPIiiiii  iIIIIIII"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE) /* S4_storeirb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) = clrbit ( #U5 )" , "0011 111 1- 00sssss  PP0iiiii  i10IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iand_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) = setbit ( #U5 )" , "0011 111 1- 00sssss  PP0iiiii  i11IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_ior_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + #u6:0 ) |= Rt32"          , "0011 111 0- 00sssss  PP0iiiii  i11ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_or_memopb_io */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #0 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  0--00ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerbnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #0 ) = Rt32"      , "0011 1011 000  sssss  PP0uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerb_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #1 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  1--00ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerbnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #1 ) = Rt32"      , "0011 1011 000  sssss  PP0uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerb_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #2 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  0--00ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerbnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #2 ) = Rt32"      , "0011 1011 000  sssss  PP1uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerb_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #3 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  1--00ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerbnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memb ( Rs32 + Ru32 << #3 ) = Rt32"      , "0011 1011 000  sssss  PP1uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerb_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "11110010uuuuIIIIEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storebi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "11110010uuuuIIIIEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storebi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "11110010uuuuIIIIEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storeh_io */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "11110010uuuuIIIIEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storewi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "11110010uuuuIIIIEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi0_SS2_storewi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #1 ; memb ( Rs16 + #u4:0 ) = #0" , "11110011uuuuIIIIEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storebi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #1 ; memb ( Rs16 + #u4:0 ) = #1" , "11110011uuuuIIIIEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storebi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #1 ; memh ( Rs16 + #u3:1 ) = Rt16" , "11110011uuuuIIIIEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storeh_io */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #1 ; memw ( Rs16 + #u4:2 ) = #0" , "11110011uuuuIIIIEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storewi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = #1 ; memw ( Rs16 + #u4:2 ) = #1" , "11110011uuuuIIIIEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storebi1_SS2_storewi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #0" , "1011IIIIuuuuttttEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storebi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #1" , "1011IIIIuuuuttttEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storebi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #0" , "1011IIIIuuuuttttEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storewi0 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #1" , "1011IIIIuuuuttttEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storewi1 */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rv16 ; memb ( Rs16 + #u4:0 ) = Rt16" , "1011IIIIuuuuvvvvEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS1_storeb_io */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rv16 ; memh ( Rs16 + #u3:1 ) = Rt16" , "1011IIIIuuuuvvvvEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS2_storeh_io */
HEXAGON_OPCODE ("memb ( Ru16 + #U4:0 ) = Rv16 ; memw ( Rs16 + #u4:2 ) = Rt16" , "1011IIIIuuuuvvvvEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storeb_io_SS1_storew_io */
HEXAGON_OPCODE ("memb ( Ru32 << #0 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP000ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerbnew_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memb ( Ru32 << #0 + #U6 ) = Rt32"       , "1010 1 10 1 000  uuuuu  PP0ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerb_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memb ( Ru32 << #1 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP000ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerbnew_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memb ( Ru32 << #1 + #U6 ) = Rt32"       , "1010 1 10 1 000  uuuuu  PP0ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerb_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memb ( Ru32 << #2 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP100ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerbnew_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memb ( Ru32 << #2 + #U6 ) = Rt32"       , "1010 1 10 1 000  uuuuu  PP1ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerb_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memb ( Ru32 << #3 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP100ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerbnew_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memb ( Ru32 << #3 + #U6 ) = Rt32"       , "1010 1 10 1 000  uuuuu  PP1ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerb_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memb ( Rz32 ++ #s4:0 ) = Nt8 .new"      , "1010 1 01 1 101  zzzzz  PP000ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerbnew_pi */
HEXAGON_OPCODE ("memb ( Rz32 ++ #s4:0 ) = Rt32"          , "1010 1 01 1 000  zzzzz  PP0ttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerb_pi */
HEXAGON_OPCODE ("memb ( Rz32 ++ #s4:0 :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu00ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerbnew_pci */
HEXAGON_OPCODE ("memb ( Rz32 ++ #s4:0 :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 000  zzzzz  PPuttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerb_pci */
HEXAGON_OPCODE ("memb ( Rz32 ++ Mu2 ) = Nt8 .new"        , "1010 1 10 1 101  zzzzz  PPu00ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerbnew_pr */
HEXAGON_OPCODE ("memb ( Rz32 ++ Mu2 ) = Rt32"            , "1010 1 10 1 000  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerb_pr */
HEXAGON_OPCODE ("memb ( Rz32 ++ Mu2 :brev ) = Nt8 .new"  , "1010 1 11 1 101  zzzzz  PPu00ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerbnew_pbr */
HEXAGON_OPCODE ("memb ( Rz32 ++ Mu2 :brev ) = Rt32"      , "1010 1 11 1 000  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerb_pbr */
HEXAGON_OPCODE ("memb ( Rz32 ++I :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu00ttt  0-----1-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerbnew_pcr */
HEXAGON_OPCODE ("memb ( Rz32 ++I :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 000  zzzzz  PPuttttt  0-----1-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerb_pcr */
HEXAGON_OPCODE ("memd ( #g16:3 ) = Rtt32"                , "0100 1ii0 110  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerdgp */
HEXAGON_OPCODE ("memd ( gp + #u16:3 ) = Rtt32"           , "0100 1ii0 110  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerdgp */
HEXAGON_OPCODE ("memd ( Rf32 = #U6 ) = Rtt32"            , "1010 1 01 1 110  fffff  PP0ttttt  1-IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerd_ap */
HEXAGON_MAPPING ("memd ( Rs32 ) = Rtt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerd_zomap)) /* mapped to memd(Rs32+#0)=Rtt32 */
HEXAGON_OPCODE ("memd ( Rs32 + #s11:3 ) = Rtt32"         , "1010 0 ii 1 110  sssss  PPittttt  iiiiiiii" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerd_io */
HEXAGON_OPCODE ("memd ( Rs32 + Ru32 << #0 ) = Rtt32"     , "0011 1011 110  sssss  PP0uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerd_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memd ( Rs32 + Ru32 << #1 ) = Rtt32"     , "0011 1011 110  sssss  PP0uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerd_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memd ( Rs32 + Ru32 << #2 ) = Rtt32"     , "0011 1011 110  sssss  PP1uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerd_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memd ( Rs32 + Ru32 << #3 ) = Rtt32"     , "0011 1011 110  sssss  PP1uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerd_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memd ( Ru32 << #0 + #U6 ) = Rtt32"      , "1010 1 10 1 110  uuuuu  PP0ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerd_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memd ( Ru32 << #1 + #U6 ) = Rtt32"      , "1010 1 10 1 110  uuuuu  PP0ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerd_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memd ( Ru32 << #2 + #U6 ) = Rtt32"      , "1010 1 10 1 110  uuuuu  PP1ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerd_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memd ( Ru32 << #3 + #U6 ) = Rtt32"      , "1010 1 10 1 110  uuuuu  PP1ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerd_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memd ( Rz32 ++ #s4:3 ) = Rtt32"         , "1010 1 01 1 110  zzzzz  PP0ttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerd_pi */
HEXAGON_OPCODE ("memd ( Rz32 ++ #s4:3 :circ ( Mu2 ) ) = Rtt32" , "1010 1 00 1 110  zzzzz  PPuttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerd_pci */
HEXAGON_OPCODE ("memd ( Rz32 ++ Mu2 ) = Rtt32"           , "1010 1 10 1 110  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerd_pr */
HEXAGON_OPCODE ("memd ( Rz32 ++ Mu2 :brev ) = Rtt32"     , "1010 1 11 1 110  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerd_pbr */
HEXAGON_OPCODE ("memd ( Rz32 ++I :circ ( Mu2 ) ) = Rtt32" , "1010 1 00 1 110  zzzzz  PPuttttt  0-----1-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerd_pcr */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rtt8 ; allocframe ( #u5:3 )" , "1110101IIIIIItttEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_allocframe */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rtt8 ; memb ( Rs16 + #u4:0 ) = #0" , "1110101IIIIIItttEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storebi0 */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rtt8 ; memb ( Rs16 + #u4:0 ) = #1" , "1110101IIIIIItttEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storebi1 */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rtt8 ; memw ( Rs16 + #u4:2 ) = #0" , "1110101IIIIIItttEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storewi0 */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rtt8 ; memw ( Rs16 + #u4:2 ) = #1" , "1110101IIIIIItttEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storewi1 */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rvv8 ; memd ( Sp + #s6:3 ) = Rtt8" , "1110101IIIIIIvvvEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_stored_sp */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rvv8 ; memh ( Rs16 + #u3:1 ) = Rt16" , "1110101IIIIIIvvvEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storeh_io */
HEXAGON_OPCODE ("memd ( Sp + #S6:3 ) = Rvv8 ; memw ( Sp + #u5:2 ) = Rt16" , "1110101IIIIIIvvvEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_stored_sp_SS2_storew_sp */
HEXAGON_OPCODE ("memd_locked ( Rs32 , Pd4 ) = Rtt32"     , "1010 000 01 11sssss PP-ttttt ------dd"      , 0x1, 0, 0|A_STORE|A_RESTRICT_AX|A_LATEPRED|A_MEMORY) /* S4_stored_locked */
HEXAGON_OPCODE ("memh ( #g16:1 ) = Nt8 .new"             , "0100 1ii0 101  iiiii  PPi01ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerhnewgp */
HEXAGON_OPCODE ("memh ( #g16:1 ) = Rt32.h"               , "0100 1ii0 011  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerfgp */
HEXAGON_OPCODE ("memh ( #g16:1 ) = Rt32"                 , "0100 1ii0 010  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerhgp */
HEXAGON_OPCODE ("memh ( gp + #u16:1 ) = Nt8 .new"        , "0100 1ii0 101  iiiii  PPi01ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerhnewgp */
HEXAGON_OPCODE ("memh ( gp + #u16:1 ) = Rt32.h"          , "0100 1ii0 011  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerfgp */
HEXAGON_OPCODE ("memh ( gp + #u16:1 ) = Rt32"            , "0100 1ii0 010  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerhgp */
HEXAGON_OPCODE ("memh ( Rf32 = #U6 ) = Nt8 .new"         , "1010 1 01 1 101  fffff  PP001ttt  1-IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerhnew_ap */
HEXAGON_OPCODE ("memh ( Rf32 = #U6 ) = Rt32.h"           , "1010 1 01 1 011  fffff  PP0ttttt  1-IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerf_ap */
HEXAGON_OPCODE ("memh ( Rf32 = #U6 ) = Rt32"             , "1010 1 01 1 010  fffff  PP0ttttt  1-IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerh_ap */
HEXAGON_OPCODE ("memh ( Rs16 + #U3:1 ) = Rt16 ; allocframe ( #u5:3 )" , "11100IIIssssttttEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_allocframe */
HEXAGON_OPCODE ("memh ( Rs16 + #U3:1 ) = Rv16 ; memd ( Sp + #s6:3 ) = Rtt8" , "11100IIIssssvvvvEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_stored_sp */
HEXAGON_OPCODE ("memh ( Rs16 + #U3:1 ) = Rv16 ; memw ( Sp + #u5:2 ) = Rt16" , "11100IIIssssvvvvEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storew_sp */
HEXAGON_MAPPING ("memh ( Rs32 ) &= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_and_memoph_zomap)) /* mapped to memh(Rs32+#0)&=Rt32 */
HEXAGON_MAPPING ("memh ( Rs32 ) += #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iadd_memoph_zomap)) /* mapped to memh(Rs32+#0)+=#U5 */
HEXAGON_MAPPING ("memh ( Rs32 ) += Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_add_memoph_zomap)) /* mapped to memh(Rs32+#0)+=Rt32 */
HEXAGON_MAPPING ("memh ( Rs32 ) -= #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_isub_memoph_zomap)) /* mapped to memh(Rs32+#0)-=#U5 */
HEXAGON_MAPPING ("memh ( Rs32 ) -= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_sub_memoph_zomap)) /* mapped to memh(Rs32+#0)-=Rt32 */
HEXAGON_MAPPING ("memh ( Rs32 ) = #S8"                    , "0000IIIIIIIIsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeirh_zomap)) /* mapped to memh(Rs32+#0)=#S8 */
HEXAGON_MAPPING ("memh ( Rs32 ) = Nt8 .new"               , "0000tttsssss00000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerhnew_zomap)) /* mapped to memh(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("memh ( Rs32 ) = Rt32.h"                 , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerf_zomap)) /* mapped to memh(Rs32+#0)=Rt32.h */
HEXAGON_MAPPING ("memh ( Rs32 ) = Rt32"                   , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerh_zomap)) /* mapped to memh(Rs32+#0)=Rt32 */
HEXAGON_MAPPING ("memh ( Rs32 ) = clrbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iand_memoph_zomap)) /* mapped to memh(Rs32+#0)=clrbit(#U5) */
HEXAGON_MAPPING ("memh ( Rs32 ) = setbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_ior_memoph_zomap)) /* mapped to memh(Rs32+#0)=setbit(#U5) */
HEXAGON_MAPPING ("memh ( Rs32 ) |= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_or_memoph_zomap)) /* mapped to memh(Rs32+#0)|=Rt32 */
HEXAGON_OPCODE ("memh ( Rs32 + #s11:1 ) = Nt8 .new"      , "1010 0 ii 1 101  sssss  PPi01ttt  iiiiiiii" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerhnew_io */
HEXAGON_OPCODE ("memh ( Rs32 + #s11:1 ) = Rt32.h"        , "1010 0 ii 1 011  sssss  PPittttt  iiiiiiii" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerf_io */
HEXAGON_OPCODE ("memh ( Rs32 + #s11:1 ) = Rt32"          , "1010 0 ii 1 010  sssss  PPittttt  iiiiiiii" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerh_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) &= Rt32"          , "0011 111 0- 01sssss  PP0iiiii  i10ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_and_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) += #U5"           , "0011 111 1- 01sssss  PP0iiiii  i00IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iadd_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) += Rt32"          , "0011 111 0- 01sssss  PP0iiiii  i00ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_add_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) -= #U5"           , "0011 111 1- 01sssss  PP0iiiii  i01IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_isub_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) -= Rt32"          , "0011 111 0- 01sssss  PP0iiiii  i01ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_sub_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) = #S8"            , "0011 110 -- 01  sssss  PPIiiiii  iIIIIIII"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE) /* S4_storeirh_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) = clrbit ( #U5 )" , "0011 111 1- 01sssss  PP0iiiii  i10IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iand_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) = setbit ( #U5 )" , "0011 111 1- 01sssss  PP0iiiii  i11IIIII"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_ior_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + #u6:1 ) |= Rt32"          , "0011 111 0- 01sssss  PP0iiiii  i11ttttt"    , 0x1, 0, 0|A_RESTRICT_SLOT1_NOSTORE|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_or_memoph_io */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #0 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  0--01ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerhnew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #0 ) = Rt32.h"    , "0011 1011 011  sssss  PP0uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerf_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #0 ) = Rt32"      , "0011 1011 010  sssss  PP0uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerh_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #1 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  1--01ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerhnew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #1 ) = Rt32.h"    , "0011 1011 011  sssss  PP0uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerf_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #1 ) = Rt32"      , "0011 1011 010  sssss  PP0uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerh_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #2 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  0--01ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerhnew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #2 ) = Rt32.h"    , "0011 1011 011  sssss  PP1uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerf_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #2 ) = Rt32"      , "0011 1011 010  sssss  PP1uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerh_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #3 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  1--01ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerhnew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #3 ) = Rt32.h"    , "0011 1011 011  sssss  PP1uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerf_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Rs32 + Ru32 << #3 ) = Rt32"      , "0011 1011 010  sssss  PP1uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storerh_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Ru16 + #U3:1 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #0" , "11100IIIuuuuttttEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storebi0 */
HEXAGON_OPCODE ("memh ( Ru16 + #U3:1 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #1" , "11100IIIuuuuttttEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storebi1 */
HEXAGON_OPCODE ("memh ( Ru16 + #U3:1 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #0" , "11100IIIuuuuttttEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storewi0 */
HEXAGON_OPCODE ("memh ( Ru16 + #U3:1 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #1" , "11100IIIuuuuttttEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storewi1 */
HEXAGON_OPCODE ("memh ( Ru16 + #U3:1 ) = Rv16 ; memh ( Rs16 + #u3:1 ) = Rt16" , "11100IIIuuuuvvvvEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storeh_io_SS2_storeh_io */
HEXAGON_OPCODE ("memh ( Ru32 << #0 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP001ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerhnew_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Ru32 << #0 + #U6 ) = Rt32.h"     , "1010 1 10 1 011  uuuuu  PP0ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerf_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Ru32 << #0 + #U6 ) = Rt32"       , "1010 1 10 1 010  uuuuu  PP0ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerh_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memh ( Ru32 << #1 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP001ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerhnew_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Ru32 << #1 + #U6 ) = Rt32.h"     , "1010 1 10 1 011  uuuuu  PP0ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerf_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Ru32 << #1 + #U6 ) = Rt32"       , "1010 1 10 1 010  uuuuu  PP0ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerh_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memh ( Ru32 << #2 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP101ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerhnew_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Ru32 << #2 + #U6 ) = Rt32.h"     , "1010 1 10 1 011  uuuuu  PP1ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerf_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Ru32 << #2 + #U6 ) = Rt32"       , "1010 1 10 1 010  uuuuu  PP1ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerh_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memh ( Ru32 << #3 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP101ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerhnew_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Ru32 << #3 + #U6 ) = Rt32.h"     , "1010 1 10 1 011  uuuuu  PP1ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerf_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Ru32 << #3 + #U6 ) = Rt32"       , "1010 1 10 1 010  uuuuu  PP1ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerh_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 ) = Nt8 .new"      , "1010 1 01 1 101  zzzzz  PP001ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerhnew_pi */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 ) = Rt32.h"        , "1010 1 01 1 011  zzzzz  PP0ttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerf_pi */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 ) = Rt32"          , "1010 1 01 1 010  zzzzz  PP0ttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerh_pi */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu01ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerhnew_pci */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 :circ ( Mu2 ) ) = Rt32.h" , "1010 1 00 1 011  zzzzz  PPuttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerf_pci */
HEXAGON_OPCODE ("memh ( Rz32 ++ #s4:1 :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 010  zzzzz  PPuttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerh_pci */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 ) = Nt8 .new"        , "1010 1 10 1 101  zzzzz  PPu01ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerhnew_pr */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 ) = Rt32.h"          , "1010 1 10 1 011  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerf_pr */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 ) = Rt32"            , "1010 1 10 1 010  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerh_pr */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 :brev ) = Nt8 .new"  , "1010 1 11 1 101  zzzzz  PPu01ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerhnew_pbr */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 :brev ) = Rt32.h"    , "1010 1 11 1 011  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerf_pbr */
HEXAGON_OPCODE ("memh ( Rz32 ++ Mu2 :brev ) = Rt32"      , "1010 1 11 1 010  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerh_pbr */
HEXAGON_OPCODE ("memh ( Rz32 ++I :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu01ttt  0-----1-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerhnew_pcr */
HEXAGON_OPCODE ("memh ( Rz32 ++I :circ ( Mu2 ) ) = Rt32.h" , "1010 1 00 1 011  zzzzz  PPuttttt  0-----1-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerf_pcr */
HEXAGON_OPCODE ("memh ( Rz32 ++I :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 010  zzzzz  PPuttttt  0-----1-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storerh_pcr */
HEXAGON_OPCODE ("memw ( #g16:2 ) = Nt8 .new"             , "0100 1ii0 101  iiiii  PPi10ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerinewgp */
HEXAGON_OPCODE ("memw ( #g16:2 ) = Rt32"                 , "0100 1ii0 100  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerigp */
HEXAGON_OPCODE ("memw ( gp + #u16:2 ) = Nt8 .new"        , "0100 1ii0 101  iiiii  PPi10ttt  iiiiiiii"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerinewgp */
HEXAGON_OPCODE ("memw ( gp + #u16:2 ) = Rt32"            , "0100 1ii0 100  iiiii  PPittttt  iiiiiiii"   , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storerigp */
HEXAGON_OPCODE ("memw ( Rf32 = #U6 ) = Nt8 .new"         , "1010 1 01 1 101  fffff  PP010ttt  1-IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerinew_ap */
HEXAGON_OPCODE ("memw ( Rf32 = #U6 ) = Rt32"             , "1010 1 01 1 100  fffff  PP0ttttt  1-IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storeri_ap */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #0 ; allocframe ( #u5:3 )" , "11110000ssssIIIIEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_allocframe */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #0 ; memd ( Sp + #s6:3 ) = Rtt8" , "11110000ssssIIIIEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_stored_sp */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #0 ; memw ( Sp + #u5:2 ) = Rt16" , "11110000ssssIIIIEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storew_sp */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #1 ; allocframe ( #u5:3 )" , "11110001ssssIIIIEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_allocframe */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #1 ; memd ( Sp + #s6:3 ) = Rtt8" , "11110001ssssIIIIEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_stored_sp */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = #1 ; memw ( Sp + #u5:2 ) = Rt16" , "11110001ssssIIIIEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storew_sp */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = Rt16 ; allocframe ( #u5:3 )" , "1010IIIIssssttttEE11110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_allocframe */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = Rv16 ; memd ( Sp + #s6:3 ) = Rtt8" , "1010IIIIssssvvvvEE10101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_stored_sp */
HEXAGON_OPCODE ("memw ( Rs16 + #U4:2 ) = Rv16 ; memw ( Sp + #u5:2 ) = Rt16" , "1010IIIIssssvvvvEE10100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storew_sp */
HEXAGON_MAPPING ("memw ( Rs32 ) &= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_and_memopw_zomap)) /* mapped to memw(Rs32+#0)&=Rt32 */
HEXAGON_MAPPING ("memw ( Rs32 ) += #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iadd_memopw_zomap)) /* mapped to memw(Rs32+#0)+=#U5 */
HEXAGON_MAPPING ("memw ( Rs32 ) += Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_add_memopw_zomap)) /* mapped to memw(Rs32+#0)+=Rt32 */
HEXAGON_MAPPING ("memw ( Rs32 ) -= #U5"                   , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_isub_memopw_zomap)) /* mapped to memw(Rs32+#0)-=#U5 */
HEXAGON_MAPPING ("memw ( Rs32 ) -= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_sub_memopw_zomap)) /* mapped to memw(Rs32+#0)-=Rt32 */
HEXAGON_MAPPING ("memw ( Rs32 ) = #S8"                    , "0000IIIIIIIIsssss000000000000000"           , HEXAGON_MAP_FNAME(S4_storeiri_zomap)) /* mapped to memw(Rs32+#0)=#S8 */
HEXAGON_MAPPING ("memw ( Rs32 ) = Nt8 .new"               , "0000tttsssss00000000000000000000"           , HEXAGON_MAP_FNAME(S2_storerinew_zomap)) /* mapped to memw(Rs32+#0)=Nt8.new */
HEXAGON_MAPPING ("memw ( Rs32 ) = Rt32"                   , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(S2_storeri_zomap)) /* mapped to memw(Rs32+#0)=Rt32 */
HEXAGON_MAPPING ("memw ( Rs32 ) = clrbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_iand_memopw_zomap)) /* mapped to memw(Rs32+#0)=clrbit(#U5) */
HEXAGON_MAPPING ("memw ( Rs32 ) = setbit ( #U5 )"         , "0000IIIIIsssss000000000000000000"           , HEXAGON_MAP_FNAME(L4_ior_memopw_zomap)) /* mapped to memw(Rs32+#0)=setbit(#U5) */
HEXAGON_MAPPING ("memw ( Rs32 ) |= Rt32"                  , "0000sssssttttt000000000000000000"           , HEXAGON_MAP_FNAME(L4_or_memopw_zomap)) /* mapped to memw(Rs32+#0)|=Rt32 */
HEXAGON_OPCODE ("memw ( Rs32 + #s11:2 ) = Nt8 .new"      , "1010 0 ii 1 101  sssss  PPi10ttt  iiiiiiii" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_LOWERCASE) /* S2_storerinew_io */
HEXAGON_OPCODE ("memw ( Rs32 + #s11:2 ) = Rt32"          , "1010 0 ii 1 100  sssss  PPittttt  iiiiiiii" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* S2_storeri_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) &= Rt32"          , "0011 111 0- 10sssss  PP0iiiii  i10ttttt"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_and_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) += #U5"           , "0011 111 1- 10sssss  PP0iiiii  i00IIIII"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iadd_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) += Rt32"          , "0011 111 0- 10sssss  PP0iiiii  i00ttttt"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_add_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) -= #U5"           , "0011 111 1- 10sssss  PP0iiiii  i01IIIII"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_isub_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) -= Rt32"          , "0011 111 0- 10sssss  PP0iiiii  i01ttttt"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_sub_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) = #S8"            , "0011 110 -- 10  sssss  PPIiiiii  iIIIIIII"  , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE) /* S4_storeiri_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) = clrbit ( #U5 )" , "0011 111 1- 10sssss  PP0iiiii  i10IIIII"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_iand_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) = setbit ( #U5 )" , "0011 111 1- 10sssss  PP0iiiii  i11IIIII"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_ior_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + #u6:2 ) |= Rt32"          , "0011 111 0- 10sssss  PP0iiiii  i11ttttt"    , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_EXTENDABLE_LOWERCASE) /* L4_or_memopw_io */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #0 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  0--10ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerinew_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #0 ) = Rt32"      , "0011 1011 100  sssss  PP0uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storeri_rr_expand_shamt_0 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #1 ) = Nt8 .new"  , "0011 1011 101  sssss  PP0uuuuu  1--10ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerinew_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #1 ) = Rt32"      , "0011 1011 100  sssss  PP0uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storeri_rr_expand_shamt_1 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #2 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  0--10ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerinew_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #2 ) = Rt32"      , "0011 1011 100  sssss  PP1uuuuu  0--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storeri_rr_expand_shamt_2 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #3 ) = Nt8 .new"  , "0011 1011 101  sssss  PP1uuuuu  1--10ttt"   , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S4_storerinew_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memw ( Rs32 + Ru32 << #3 ) = Rt32"      , "0011 1011 100  sssss  PP1uuuuu  1--ttttt"   , 0x3, 0, 0|A_STORE|A_MEMORY) /* S4_storeri_rr_expand_shamt_3 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #0 ; memb ( Rs16 + #u4:0 ) = #0" , "11110000uuuuIIIIEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storebi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #0 ; memb ( Rs16 + #u4:0 ) = #1" , "11110000uuuuIIIIEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storebi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #0 ; memh ( Rs16 + #u3:1 ) = Rt16" , "11110000uuuuIIIIEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storeh_io */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #0 ; memw ( Rs16 + #u4:2 ) = #0" , "11110000uuuuIIIIEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storewi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #0 ; memw ( Rs16 + #u4:2 ) = #1" , "11110000uuuuIIIIEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi0_SS2_storewi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #1 ; memb ( Rs16 + #u4:0 ) = #0" , "11110001uuuuIIIIEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storebi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #1 ; memb ( Rs16 + #u4:0 ) = #1" , "11110001uuuuIIIIEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storebi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #1 ; memh ( Rs16 + #u3:1 ) = Rt16" , "11110001uuuuIIIIEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storeh_io */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #1 ; memw ( Rs16 + #u4:2 ) = #0" , "11110001uuuuIIIIEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storewi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = #1 ; memw ( Rs16 + #u4:2 ) = #1" , "11110001uuuuIIIIEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storewi1_SS2_storewi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #0" , "1010IIIIuuuuttttEE110010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storebi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #1" , "1010IIIIuuuuttttEE110011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storebi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #0" , "1010IIIIuuuuttttEE110000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storewi0 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #1" , "1010IIIIuuuuttttEE110001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storewi1 */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rv16 ; memb ( Rs16 + #u4:0 ) = Rt16" , "1010IIIIuuuuvvvvEE01iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS1_storeb_io */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rv16 ; memh ( Rs16 + #u3:1 ) = Rt16" , "1010IIIIuuuuvvvvEE100iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS2_storeh_io */
HEXAGON_OPCODE ("memw ( Ru16 + #U4:2 ) = Rv16 ; memw ( Rs16 + #u4:2 ) = Rt16" , "1010IIIIuuuuvvvvEE00iiiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS1_storew_io_SS1_storew_io */
HEXAGON_OPCODE ("memw ( Ru32 << #0 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP010ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerinew_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memw ( Ru32 << #0 + #U6 ) = Rt32"       , "1010 1 10 1 100  uuuuu  PP0ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storeri_ur_expand_shamt_0 */
HEXAGON_OPCODE ("memw ( Ru32 << #1 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP010ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerinew_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memw ( Ru32 << #1 + #U6 ) = Rt32"       , "1010 1 10 1 100  uuuuu  PP0ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storeri_ur_expand_shamt_1 */
HEXAGON_OPCODE ("memw ( Ru32 << #2 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP110ttt  10IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerinew_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memw ( Ru32 << #2 + #U6 ) = Rt32"       , "1010 1 10 1 100  uuuuu  PP1ttttt  10IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storeri_ur_expand_shamt_2 */
HEXAGON_OPCODE ("memw ( Ru32 << #3 + #U6 ) = Nt8 .new"   , "1010 1 10 1 101  uuuuu  PP110ttt  11IIIIII" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storerinew_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memw ( Ru32 << #3 + #U6 ) = Rt32"       , "1010 1 10 1 100  uuuuu  PP1ttttt  11IIIIII" , 0x3, 0, 0|A_STORE|A_MEMORY|A_EXTENDABLE_UPPERCASE|A_MUST_EXTEND) /* S4_storeri_ur_expand_shamt_3 */
HEXAGON_OPCODE ("memw ( Rz32 ++ #s4:2 ) = Nt8 .new"      , "1010 1 01 1 101  zzzzz  PP010ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerinew_pi */
HEXAGON_OPCODE ("memw ( Rz32 ++ #s4:2 ) = Rt32"          , "1010 1 01 1 100  zzzzz  PP0ttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storeri_pi */
HEXAGON_OPCODE ("memw ( Rz32 ++ #s4:2 :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu10ttt  0iiii-0-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerinew_pci */
HEXAGON_OPCODE ("memw ( Rz32 ++ #s4:2 :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 100  zzzzz  PPuttttt  0iiii-0-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storeri_pci */
HEXAGON_OPCODE ("memw ( Rz32 ++ Mu2 ) = Nt8 .new"        , "1010 1 10 1 101  zzzzz  PPu10ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerinew_pr */
HEXAGON_OPCODE ("memw ( Rz32 ++ Mu2 ) = Rt32"            , "1010 1 10 1 100  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storeri_pr */
HEXAGON_OPCODE ("memw ( Rz32 ++ Mu2 :brev ) = Nt8 .new"  , "1010 1 11 1 101  zzzzz  PPu10ttt  0-------" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerinew_pbr */
HEXAGON_OPCODE ("memw ( Rz32 ++ Mu2 :brev ) = Rt32"      , "1010 1 11 1 100  zzzzz  PPuttttt  0-------" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storeri_pbr */
HEXAGON_OPCODE ("memw ( Rz32 ++I :circ ( Mu2 ) ) = Nt8 .new" , "1010 1 00 1 101  zzzzz  PPu10ttt  0-----1-" , 0x1, 0, 0|A_STORE|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC) /* S2_storerinew_pcr */
HEXAGON_OPCODE ("memw ( Rz32 ++I :circ ( Mu2 ) ) = Rt32" , "1010 1 00 1 100  zzzzz  PPuttttt  0-----1-" , 0x3, 0, 0|A_STORE|A_MEMORY) /* S2_storeri_pcr */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rt16 ; allocframe ( #u5:3 )" , "1110100IIIIIttttEE01110iiiii----"           , 0x1, 0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_allocframe */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #0" , "1110100IIIIIttttEE010010ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storebi0 */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rt16 ; memb ( Rs16 + #u4:0 ) = #1" , "1110100IIIIIttttEE010011ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storebi1 */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #0" , "1110100IIIIIttttEE010000ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storewi0 */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rt16 ; memw ( Rs16 + #u4:2 ) = #1" , "1110100IIIIIttttEE010001ssssiiii"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storewi1 */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rv16 ; memd ( Sp + #s6:3 ) = Rtt8" , "1110100IIIIIvvvvEE00101iiiiiittt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_stored_sp */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rv16 ; memh ( Rs16 + #u3:1 ) = Rt16" , "1110100IIIIIvvvvEE000iiisssstttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storeh_io */
HEXAGON_OPCODE ("memw ( Sp + #U5:2 ) = Rv16 ; memw ( Sp + #u5:2 ) = Rt16" , "1110100IIIIIvvvvEE00100iiiiitttt"           , 0x1, 0, 0|A_STORE|A_MEMORY|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SS2_storew_sp_SS2_storew_sp */
HEXAGON_OPCODE ("memw_locked ( Rs32 , Pd4 ) = Rt32"      , "1010 000 01 01sssss PP-ttttt ------dd"      , 0x1, 0, 0|A_STORE|A_RESTRICT_AX|A_LATEPRED|A_MEMORY) /* S2_storew_locked */
HEXAGON_OPCODE ("nmi ( Rs32 )"                           , "0110 0100 011sssss PP------ 010-----"       , 0x8, 0, 0|A_SOLO) /* Y4_nmi */
HEXAGON_OPCODE ("nop"                                    , "0111 1111 -------- PP------ --------"       , 0xf, 0, 0|A_NOP) /* A2_nop */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #-1 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  1iissss  PP0---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #-1 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0  11  1iissss  PP1---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #-1 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  0iissss  PP0---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #-1 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0  11  0iissss  PP1---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rd16 = #-1" , "00111001ssss--IIEE11101--0--dddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_setin1 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rd16 = memw ( Sp + #u5:2 )" , "01011001ssss--IIEE11110iiiiidddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_loadri_sp */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rdd8 = combine ( #0 , #u2 )" , "00111001ssss--IIEE1111-0-ii00ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combine0i */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rdd8 = combine ( #1 , #u2 )" , "00111001ssss--IIEE1111-0-ii01ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combine1i */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rdd8 = combine ( #2 , #u2 )" , "00111001ssss--IIEE1111-0-ii10ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combine2i */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rdd8 = combine ( #3 , #u2 )" , "00111001ssss--IIEE1111-0-ii11ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combine3i */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; Rdd8 = memd ( Sp + #u5:3 )" , "01011001ssss--IIEE111110iiiiiddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_loadrd_sp */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; allocframe ( #u5:3 )" , "01111001ssss--IIEE11110iiiii----"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_SP|IMPLICIT_FP, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_allocframe */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; if ( ! p0 ) Rd16 = #0" , "00111001ssss--IIEE11101--111dddd"           , 0x1, 0|IMPLICIT_P0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_clrf */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; if ( ! p0 .new ) Rd16 = #0" , "00111001ssss--IIEE11101--101dddd"           , 0x1, 0|IMPLICIT_P0, 0|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_clrfnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; if ( p0 ) Rd16 = #0" , "00111001ssss--IIEE11101--110dddd"           , 0x1, 0|IMPLICIT_P0, 0|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_clrt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; if ( p0 .new ) Rd16 = #0" , "00111001ssss--IIEE11101--100dddd"           , 0x1, 0|IMPLICIT_P0, 0|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_clrtnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; memd ( Sp + #s6:3 ) = Rtt8" , "01111001ssss--IIEE10101iiiiiittt"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_stored_sp */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U2 ) ; memw ( Sp + #u5:2 ) = Rt16" , "01111001ssss--IIEE10100iiiiitttt"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storew_sp */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0 00  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0 00  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U5 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0 00  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #U5 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0 00  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; dealloc_return" , "01011001ssss--iiEE11111101---0--"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP|IMPLICIT_PC, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_return */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; deallocframe" , "01011001ssss--iiEE11111100---0--"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_SP|IMPLICIT_FP, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_deallocframe */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( ! p0 ) dealloc_return" , "01011001ssss--iiEE11111101---101"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_return_f */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( ! p0 ) jumpr Lr" , "01011001ssss--iiEE11111111---101"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_jumpr31_f */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( ! p0 .new ) dealloc_return:nt" , "01011001ssss--iiEE11111101---111"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_return_fnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( ! p0 .new ) jumpr:nt Lr" , "01011001ssss--iiEE11111111---111"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_jumpr31_fnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( p0 ) dealloc_return" , "01011001ssss--iiEE11111101---100"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_return_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( p0 ) jumpr Lr" , "01011001ssss--iiEE11111111---100"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_jumpr31_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( p0 .new ) dealloc_return:nt" , "01011001ssss--iiEE11111101---110"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_LR|IMPLICIT_PC|IMPLICIT_SP|IMPLICIT_FP, 0|A_BRANCH|A_RESTRICT_SLOT1_NOSTORE|A_MEMORY|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_DEALLOCRET) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_return_tnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; if ( p0 .new ) jumpr:nt Lr" , "01011001ssss--iiEE11111111---110"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_jumpr31_tnew */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , #u2 ) ; jumpr Lr"  , "01011001ssss--iiEE11111111---0--"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_PC, 0|A_BRANCH|A_CONDEXEC|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_jumpr31 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -1 0 00  1iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -1 0 00  1iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -1 0 00  0iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.eq ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -1 0 00  0iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rd16 = memb ( Rs16 + #u3:0 )" , "01011001uuuu--IIEE110iiissssdddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_loadrb_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rd16 = memh ( Rs16 + #u3:1 )" , "01011001uuuu--IIEE100iiissssdddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_loadrh_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rd16 = memub ( Rs16 + #u4:0 )" , "01011001uuuu--IIEE01iiiissssdddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL1_loadrub_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rd16 = memuh ( Rs16 + #u3:1 )" , "01011001uuuu--IIEE101iiissssdddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL2_loadruh_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rd16 = memw ( Rs16 + #u4:2 )" , "01011001uuuu--IIEE00iiiissssdddd"           , 0x1, 0|IMPLICIT_P0, 0|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SL1_loadri_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rdd8 = combine ( #0 , Rs16 )" , "00111001uuuu--IIEE1111-1ssss0ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combinezr */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; Rdd8 = combine ( Rs16 , #0 )" , "00111001uuuu--IIEE1111-1ssss1ddd"           , 0x1, 0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_combinerz */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #0" , "01111001uuuu--IIEE110010ssssiiii"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storebi0 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memb ( Rs16 + #u4:0 ) = #1" , "01111001uuuu--IIEE110011ssssiiii"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storebi1 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memb ( Rs16 + #u4:0 ) = Rt16" , "01111001uuuu--IIEE01iiiisssstttt"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS1_storeb_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memh ( Rs16 + #u3:1 ) = Rt16" , "01111001uuuu--IIEE100iiisssstttt"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storeh_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #0" , "01111001uuuu--IIEE110000ssssiiii"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storewi0 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memw ( Rs16 + #u4:2 ) = #1" , "01111001uuuu--IIEE110001ssssiiii"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS2_storewi1 */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; memw ( Rs16 + #u4:2 ) = Rt16" , "01111001uuuu--IIEE00iiiisssstttt"           , 0x1, 0|IMPLICIT_P0, 0|A_STORE|A_MEMORY|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SS1_storew_io */
HEXAGON_OPCODE ("p0 = cmp.eq ( Ru16 , #U2 ) ; p0 = cmp.eq ( Rs16 , #u2 )" , "00111001uuuu--IIEE111001ssss--ii"           , 0x1, 0|IMPLICIT_P0|IMPLICIT_P0, 0|A_COMPOUND) /* X2_AUTOJOIN_SA1_cmpeqi_SA1_cmpeqi */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #-1 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  1iissss  PP0---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #-1 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0  11  1iissss  PP1---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #-1 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  0iissss  PP0---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #-1 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0  11  0iissss  PP1---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0 01  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0 01  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #U5 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0 01  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , #U5 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0 01  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -1 0 01  1iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -1 0 01  1iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -1 0 01  0iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gt ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -1 0 01  0iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0 10  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , #U5 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0 10  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , #U5 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0 10  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , #U5 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0 10  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_tp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -1 0 10  1iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , Rt16 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -1 0 10  1iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_fp0_jump_t */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -1 0 10  0iissss  PP00tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = cmp.gtu ( Rs16 , Rt16 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -1 0 10  0iissss  PP10tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_tp0_jump_t */
HEXAGON_OPCODE ("p0 = tstbit ( Rs16 , #0 ) ; if ( ! p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  1iissss  PP0---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_fp0_jump_nt */
HEXAGON_OPCODE ("p0 = tstbit ( Rs16 , #0 ) ; if ( ! p0 .new ) jump:t #r9:2" , "0001 -0 0  11  1iissss  PP1---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_fp0_jump_t */
HEXAGON_OPCODE ("p0 = tstbit ( Rs16 , #0 ) ; if ( p0 .new ) jump:nt #r9:2" , "0001 -0 0  11  0iissss  PP0---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_tp0_jump_nt */
HEXAGON_OPCODE ("p0 = tstbit ( Rs16 , #0 ) ; if ( p0 .new ) jump:t #r9:2" , "0001 -0 0  11  0iissss  PP1---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P0, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_tp0_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #-1 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  1iissss  PP0---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #-1 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1  11  1iissss  PP1---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #-1 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  0iissss  PP0---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #-1 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1  11  0iissss  PP1---00  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqn1_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1 00  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1 00  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #U5 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1 00  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , #U5 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1 00  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeqi_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -1 0 00  1iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -1 0 00  1iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -1 0 00  0iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.eq ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -1 0 00  0iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpeq_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #-1 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  1iissss  PP0---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #-1 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1  11  1iissss  PP1---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #-1 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  0iissss  PP0---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #-1 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1  11  0iissss  PP1---01  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtn1_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1 01  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1 01  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #U5 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1 01  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , #U5 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1 01  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgti_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -1 0 01  1iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -1 0 01  1iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -1 0 01  0iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gt ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -1 0 01  0iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgt_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1 10  1iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , #U5 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1 10  1iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , #U5 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1 10  0iissss  PP0IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , #U5 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1 10  0iissss  PP1IIIII  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtui_tp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -1 0 10  1iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , Rt16 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -1 0 10  1iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_fp1_jump_t */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -1 0 10  0iissss  PP01tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = cmp.gtu ( Rs16 , Rt16 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -1 0 10  0iissss  PP11tttt  iiiiiii-"  , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_cmpgtu_tp1_jump_t */
HEXAGON_OPCODE ("p1 = tstbit ( Rs16 , #0 ) ; if ( ! p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  1iissss  PP0---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_fp1_jump_nt */
HEXAGON_OPCODE ("p1 = tstbit ( Rs16 , #0 ) ; if ( ! p1 .new ) jump:t #r9:2" , "0001 -0 1  11  1iissss  PP1---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_INVERTED |A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_fp1_jump_t */
HEXAGON_OPCODE ("p1 = tstbit ( Rs16 , #0 ) ; if ( p1 .new ) jump:nt #r9:2" , "0001 -0 1  11  0iissss  PP0---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_tp1_jump_nt */
HEXAGON_OPCODE ("p1 = tstbit ( Rs16 , #0 ) ; if ( p1 .new ) jump:t #r9:2" , "0001 -0 1  11  0iissss  PP1---11  iiiiiii-" , 0xc, 0|IMPLICIT_PC|IMPLICIT_P1, 0|A_BRANCH|A_PCREL_BRANCH|A_DUALJUMP_2|A_DUALJUMP_1|A_CONDEXEC|A_CONDITION_DOTNEW|A_COMPOUND|A_EXTENDABLE_LOWERCASE) /* J4_tstbit0_tp1_jump_t */
HEXAGON_OPCODE ("p3 = sp1loop0 ( #r7:2 , #U10 )"         , "0110 1001  101IIIII  PP-iiiii  IIIii-II"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop1si */
HEXAGON_OPCODE ("p3 = sp1loop0 ( #r7:2 , Rs32 )"         , "0110 0000  101sssss  PP-iiiii  ---ii---"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop1sr */
HEXAGON_OPCODE ("p3 = sp2loop0 ( #r7:2 , #U10 )"         , "0110 1001  110IIIII  PP-iiiii  IIIii-II"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop2si */
HEXAGON_OPCODE ("p3 = sp2loop0 ( #r7:2 , Rs32 )"         , "0110 0000  110sssss  PP-iiiii  ---ii---"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop2sr */
HEXAGON_OPCODE ("p3 = sp3loop0 ( #r7:2 , #U10 )"         , "0110 1001  111IIIII  PP-iiiii  IIIii-II"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop3si */
HEXAGON_OPCODE ("p3 = sp3loop0 ( #r7:2 , Rs32 )"         , "0110 0000  111sssss  PP-iiiii  ---ii---"    , 0x8, 0|IMPLICIT_LC0|IMPLICIT_SA0|IMPLICIT_SR_OVF|IMPLICIT_P3, 0|A_PCREL_BRANCH|A_HWLOOP|A_LATEPRED|A_EXTENDABLE_LOWERCASE) /* J2_ploop3sr */
HEXAGON_OPCODE ("pause ( #u8 )"                          , "0101 0100  01------  PP-iiiii  ---iii--"    , 0x4, 0, 0|A_SOLO) /* J2_pause */
HEXAGON_OPCODE ("resume ( Rs32 )"                        , "0110 0100 010sssss PP------ 001-----"       , 0x8, 0, 0|A_SOLO) /* Y2_resume */
HEXAGON_OPCODE ("rteunlock"                              , "0101 0111  111-----  PP01----  000-----"    , 0x4, 0|IMPLICIT_PC, 0) /* J2_rteunlock */
HEXAGON_OPCODE ("rte"                                    , "0101 0111  111-----  PP00----  000-----"    , 0x4, 0|IMPLICIT_PC, 0) /* J2_rte */
HEXAGON_OPCODE ("setimask ( Pt4 , Rs32 )"                , "0110 0100 100sssss PP----tt 000-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_setimask */
HEXAGON_OPCODE ("siad ( Rs32 )"                          , "0110 0100 100sssss PP------ 011-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y4_siad */
HEXAGON_OPCODE ("start ( Rs32 )"                         , "0110 0100 011sssss PP------ 001-----"       , 0x8, 0, 0|A_SOLO) /* Y2_start */
HEXAGON_OPCODE ("stop ( Rs32 )"                          , "0110 0100 011sssss PP------ 000-----"       , 0x8, 0, 0|A_SOLO) /* Y2_stop */
HEXAGON_OPCODE ("swi ( Rs32 )"                           , "0110 0100 000sssss PP------ 000-----"       , 0x8, 0, 0|A_RESTRICT_AX) /* Y2_swi */
HEXAGON_OPCODE ("syncht"                                 , "1010 100 00 10----- PP------ --------"      , 0x1, 0, 0|A_SOLO) /* Y2_syncht */
HEXAGON_OPCODE ("tlbinvasid ( Rs32 )"                    , "0110 1100 101sssss PP------ --------"       , 0x8, 0, 0|A_SOLO) /* Y5_tlbasidi */
HEXAGON_OPCODE ("tlblock"                                , "0110 1100 001----- PP------ 001-----"       , 0x8, 0, 0|A_SOLO) /* Y2_tlblock */
HEXAGON_OPCODE ("tlbunlock"                              , "0110 1100 001----- PP------ 010-----"       , 0x8, 0, 0|A_SOLO) /* Y2_tlbunlock */
HEXAGON_OPCODE ("tlbw ( Rss32 , Rt32 )"                  , "0110 1100 000sssss PP0ttttt --------"       , 0x8, 0, 0|A_SOLO) /* Y2_tlbw */
HEXAGON_OPCODE ("trace ( Rs32 )"                         , "0110 0010  010sssss  PP------  --------"    , 0x8, 0, 0|A_RESTRICT_AX) /* Y4_trace */
HEXAGON_OPCODE ("trap0 ( #u8 )"                          , "0101 0100  00------  PP-iiiii  ---iii--"    , 0x4, 0, 0|A_SOLO) /* J2_trap0 */
HEXAGON_OPCODE ("trap1 ( #u8 )"                          , "0101 0100  10------  PP-iiiii  ---iii--"    , 0x4, 0, 0|A_SOLO) /* J2_trap1 */
HEXAGON_OPCODE ("wait ( Rs32 )"                          , "0110 0100 010sssss PP------ 000-----"       , 0x8, 0, 0|A_SOLO) /* Y2_wait */
