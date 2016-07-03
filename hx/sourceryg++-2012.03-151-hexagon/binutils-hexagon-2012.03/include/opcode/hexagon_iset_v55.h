HEXAGON_OPCODE ("l2gcleaninv",
  "1010 100 00 01----- PP-11--- --------", 0x1, 0, 0|A_SOLO) /* Y5_l2gcleaninv */
HEXAGON_OPCODE ("l2gclean",
  "1010 100 00 01----- PP-10--- --------", 0x1, 0, 0|A_SOLO) /* Y5_l2gclean */
HEXAGON_OPCODE ("l2gunlock",
  "1010 100 00 01----- PP-01--- --------", 0x1, 0, 0|A_SOLO) /* Y5_l2gunlock */
HEXAGON_OPCODE ("Pd4 = l2locka ( Rs32 )",
  "1010 000 01 11sssss PP1----- ------dd", 0x1, 0, 0|A_STORE|A_RESTRICT_AX|A_LATEPRED) /* Y5_l2locka */
HEXAGON_OPCODE ("l2unlocka ( Rs32 )",
  "1010 011 00 11sssss PP------ --------", 0x1, 0, 0|A_STORE|A_RESTRICT_AX|A_LATEPRED) /* Y5_l2unlocka */
HEXAGON_OPCODE ("Rxx32 , Pe4 = vacsh ( Rss32 , Rtt32 )",
  "1110 101 01 01sssss PP0ttttt 0eexxxxx", 0xc, 0|IMPLICIT_SR_OVF, 0|A_LATEPRED) /* A5_ACS */
