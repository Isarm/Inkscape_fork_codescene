
#line 1 "svg-affine-parser.rl"
// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * SVG data parser
 *
 * Authors:
 *   Marc Jeanmougin <marc.jeanmougin@telecom-paris.fr>
 *
 * Copyright (C) 2019 Marc Jeanmougin (.rl parser, CSS-transform spec)
 *
 * Released under GNU GPL v2+, read the file 'COPYING' for more information.
 *
 * THE CPP FILE IS GENERATED FROM THE RL FILE, DO NOT EDIT THE CPP
 *
 * To generate it, run
 *   ragel svg-affine-parser.rl -o svg-affine-parser.cpp
 *   sed -i 's/(true)/(true)/' svg-affine-parser.cpp
 */

#include <string>
#include <glib.h>
#include <2geom/transforms.h>
#include "svg.h"
#include "preferences.h"


#line 29 "svg-affine-parser.cpp"
static const char _svg_transform_actions[] = {
	0, 1, 0, 1, 8, 1, 11, 1, 
	12, 1, 14, 1, 15, 1, 16, 2, 
	0, 8, 2, 1, 7, 2, 2, 7, 
	2, 3, 7, 2, 4, 7, 2, 5, 
	7, 2, 6, 7, 2, 9, 10, 2, 
	12, 0, 2, 12, 13, 3, 1, 7, 
	14, 3, 2, 7, 14, 3, 3, 7, 
	14, 3, 4, 7, 14, 3, 5, 7, 
	14, 3, 6, 7, 14, 3, 12, 1, 
	7, 3, 12, 2, 7, 3, 12, 3, 
	7, 3, 12, 4, 7, 3, 12, 5, 
	7, 3, 12, 6, 7
};

static const short _svg_transform_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 5, 10, 
	19, 22, 24, 36, 46, 49, 51, 63, 
	73, 76, 78, 90, 100, 103, 105, 117, 
	127, 130, 132, 144, 154, 157, 159, 168, 
	173, 181, 182, 183, 184, 185, 186, 191, 
	200, 203, 205, 217, 227, 230, 232, 244, 
	254, 257, 259, 271, 281, 284, 286, 298, 
	308, 311, 313, 325, 335, 338, 340, 349, 
	354, 358, 360, 367, 377, 386, 390, 392, 
	402, 414, 423, 427, 429, 439, 451, 460, 
	464, 466, 476, 488, 497, 501, 503, 513, 
	525, 534, 538, 540, 550, 562, 563, 564, 
	565, 566, 567, 572, 581, 584, 586, 599, 
	610, 613, 615, 627, 637, 640, 642, 651, 
	656, 660, 662, 669, 679, 688, 692, 694, 
	704, 716, 725, 729, 731, 742, 755, 757, 
	758, 759, 760, 765, 774, 777, 779, 792, 
	803, 806, 808, 817, 822, 826, 828, 835, 
	845, 854, 858, 860, 871, 884, 885, 886, 
	888, 893, 902, 905, 907, 916, 921, 925, 
	927, 934, 944, 949, 958, 961, 963, 972, 
	977, 981, 983, 990, 1000, 1001, 1002, 1003, 
	1004, 1005, 1006, 1007, 1008, 1013, 1022, 1025, 
	1027, 1040, 1051, 1054, 1056, 1065, 1070, 1074, 
	1076, 1083, 1093, 1102, 1106, 1108, 1119, 1132, 
	1136, 1138, 1145, 1155, 1164, 1168, 1170, 1180, 
	1192, 1201, 1205, 1207, 1217, 1229, 1238, 1242, 
	1244, 1254, 1266, 1275, 1279, 1281, 1291, 1303, 
	1312, 1316, 1318, 1328, 1340, 1341, 1342, 1343, 
	1344, 1345, 1350, 1359, 1362, 1364, 1377, 1388, 
	1391, 1393, 1405, 1415, 1418, 1420, 1429, 1434, 
	1438, 1440, 1447, 1457, 1466, 1470, 1472, 1482, 
	1494, 1503, 1507, 1509, 1520, 1533, 1535, 1536, 
	1537, 1538, 1543, 1552, 1555, 1557, 1570, 1581, 
	1584, 1586, 1595, 1600, 1604, 1606, 1613, 1623, 
	1632, 1636, 1638, 1649, 1662, 1663, 1664, 1666, 
	1671, 1680, 1683, 1685, 1694, 1699, 1703, 1705, 
	1712, 1722, 1727, 1736, 1739, 1741, 1750, 1755, 
	1759, 1761, 1768, 1778, 1779, 1780, 1781, 1782, 
	1783, 1784, 1785, 1786, 1791, 1800, 1803, 1805, 
	1818, 1829, 1832, 1834, 1843, 1848, 1852, 1854, 
	1861, 1871, 1880, 1884, 1886, 1897, 1910, 1918, 
	1926, 1931, 1940, 1945, 1950, 1955, 1960
};

static const char _svg_transform_trans_keys[] = {
	97, 116, 114, 105, 120, 13, 32, 40, 
	9, 10, 13, 32, 43, 45, 46, 9, 
	10, 48, 57, 46, 48, 57, 48, 57, 
	13, 32, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 13, 32, 44, 46, 
	9, 10, 43, 45, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 44, 46, 69, 
	101, 9, 10, 43, 45, 48, 57, 13, 
	32, 44, 46, 9, 10, 43, 45, 48, 
	57, 46, 48, 57, 48, 57, 13, 32, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 13, 32, 44, 46, 9, 10, 
	43, 45, 48, 57, 46, 48, 57, 48, 
	57, 13, 32, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 13, 32, 44, 
	46, 9, 10, 43, 45, 48, 57, 46, 
	48, 57, 48, 57, 13, 32, 44, 46, 
	69, 101, 9, 10, 43, 45, 48, 57, 
	13, 32, 44, 46, 9, 10, 43, 45, 
	48, 57, 46, 48, 57, 48, 57, 13, 
	32, 41, 69, 101, 9, 10, 48, 57, 
	13, 32, 41, 9, 10, 13, 32, 109, 
	114, 115, 116, 9, 10, 97, 116, 114, 
	105, 120, 13, 32, 40, 9, 10, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	46, 48, 57, 48, 57, 13, 32, 44, 
	46, 69, 101, 9, 10, 43, 45, 48, 
	57, 13, 32, 44, 46, 9, 10, 43, 
	45, 48, 57, 46, 48, 57, 48, 57, 
	13, 32, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 13, 32, 44, 46, 
	9, 10, 43, 45, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 44, 46, 69, 
	101, 9, 10, 43, 45, 48, 57, 13, 
	32, 44, 46, 9, 10, 43, 45, 48, 
	57, 46, 48, 57, 48, 57, 13, 32, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 13, 32, 44, 46, 9, 10, 
	43, 45, 48, 57, 46, 48, 57, 48, 
	57, 13, 32, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 13, 32, 44, 
	46, 9, 10, 43, 45, 48, 57, 46, 
	48, 57, 48, 57, 13, 32, 41, 69, 
	101, 9, 10, 48, 57, 13, 32, 41, 
	9, 10, 43, 45, 48, 57, 48, 57, 
	13, 32, 41, 9, 10, 48, 57, 13, 
	32, 41, 46, 69, 101, 9, 10, 48, 
	57, 13, 32, 43, 45, 46, 9, 10, 
	48, 57, 43, 45, 48, 57, 48, 57, 
	13, 32, 44, 46, 9, 10, 43, 45, 
	48, 57, 13, 32, 44, 46, 69, 101, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	43, 45, 46, 9, 10, 48, 57, 43, 
	45, 48, 57, 48, 57, 13, 32, 44, 
	46, 9, 10, 43, 45, 48, 57, 13, 
	32, 44, 46, 69, 101, 9, 10, 43, 
	45, 48, 57, 13, 32, 43, 45, 46, 
	9, 10, 48, 57, 43, 45, 48, 57, 
	48, 57, 13, 32, 44, 46, 9, 10, 
	43, 45, 48, 57, 13, 32, 44, 46, 
	69, 101, 9, 10, 43, 45, 48, 57, 
	13, 32, 43, 45, 46, 9, 10, 48, 
	57, 43, 45, 48, 57, 48, 57, 13, 
	32, 44, 46, 9, 10, 43, 45, 48, 
	57, 13, 32, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 43, 45, 
	48, 57, 48, 57, 13, 32, 44, 46, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 111, 116, 97, 116, 101, 13, 
	32, 40, 9, 10, 13, 32, 43, 45, 
	46, 9, 10, 48, 57, 46, 48, 57, 
	48, 57, 13, 32, 41, 44, 46, 69, 
	101, 9, 10, 43, 45, 48, 57, 13, 
	32, 41, 44, 46, 9, 10, 43, 45, 
	48, 57, 46, 48, 57, 48, 57, 13, 
	32, 44, 46, 69, 101, 9, 10, 43, 
	45, 48, 57, 13, 32, 44, 46, 9, 
	10, 43, 45, 48, 57, 46, 48, 57, 
	48, 57, 13, 32, 41, 69, 101, 9, 
	10, 48, 57, 13, 32, 41, 9, 10, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	41, 9, 10, 48, 57, 13, 32, 41, 
	46, 69, 101, 9, 10, 48, 57, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	44, 46, 9, 10, 43, 45, 48, 57, 
	13, 32, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 13, 32, 43, 45, 
	46, 9, 10, 48, 57, 43, 45, 48, 
	57, 48, 57, 13, 32, 41, 44, 46, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	41, 44, 46, 69, 101, 9, 10, 43, 
	45, 48, 57, 99, 107, 97, 108, 101, 
	13, 32, 40, 9, 10, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 41, 44, 46, 
	69, 101, 9, 10, 43, 45, 48, 57, 
	13, 32, 41, 44, 46, 9, 10, 43, 
	45, 48, 57, 46, 48, 57, 48, 57, 
	13, 32, 41, 69, 101, 9, 10, 48, 
	57, 13, 32, 41, 9, 10, 43, 45, 
	48, 57, 48, 57, 13, 32, 41, 9, 
	10, 48, 57, 13, 32, 41, 46, 69, 
	101, 9, 10, 48, 57, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 43, 45, 
	48, 57, 48, 57, 13, 32, 41, 44, 
	46, 9, 10, 43, 45, 48, 57, 13, 
	32, 41, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 101, 119, 88, 89, 
	13, 32, 40, 9, 10, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 41, 69, 101, 
	9, 10, 48, 57, 13, 32, 41, 9, 
	10, 43, 45, 48, 57, 48, 57, 13, 
	32, 41, 9, 10, 48, 57, 13, 32, 
	41, 46, 69, 101, 9, 10, 48, 57, 
	13, 32, 40, 9, 10, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 41, 69, 101, 
	9, 10, 48, 57, 13, 32, 41, 9, 
	10, 43, 45, 48, 57, 48, 57, 13, 
	32, 41, 9, 10, 48, 57, 13, 32, 
	41, 46, 69, 101, 9, 10, 48, 57, 
	114, 97, 110, 115, 108, 97, 116, 101, 
	13, 32, 40, 9, 10, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 46, 48, 
	57, 48, 57, 13, 32, 41, 44, 46, 
	69, 101, 9, 10, 43, 45, 48, 57, 
	13, 32, 41, 44, 46, 9, 10, 43, 
	45, 48, 57, 46, 48, 57, 48, 57, 
	13, 32, 41, 69, 101, 9, 10, 48, 
	57, 13, 32, 41, 9, 10, 43, 45, 
	48, 57, 48, 57, 13, 32, 41, 9, 
	10, 48, 57, 13, 32, 41, 46, 69, 
	101, 9, 10, 48, 57, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 43, 45, 
	48, 57, 48, 57, 13, 32, 41, 44, 
	46, 9, 10, 43, 45, 48, 57, 13, 
	32, 41, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 43, 45, 48, 57, 
	48, 57, 13, 32, 41, 9, 10, 48, 
	57, 13, 32, 41, 46, 69, 101, 9, 
	10, 48, 57, 13, 32, 43, 45, 46, 
	9, 10, 48, 57, 43, 45, 48, 57, 
	48, 57, 13, 32, 44, 46, 9, 10, 
	43, 45, 48, 57, 13, 32, 44, 46, 
	69, 101, 9, 10, 43, 45, 48, 57, 
	13, 32, 43, 45, 46, 9, 10, 48, 
	57, 43, 45, 48, 57, 48, 57, 13, 
	32, 44, 46, 9, 10, 43, 45, 48, 
	57, 13, 32, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 13, 32, 43, 
	45, 46, 9, 10, 48, 57, 43, 45, 
	48, 57, 48, 57, 13, 32, 44, 46, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 13, 32, 43, 45, 46, 9, 
	10, 48, 57, 43, 45, 48, 57, 48, 
	57, 13, 32, 44, 46, 9, 10, 43, 
	45, 48, 57, 13, 32, 44, 46, 69, 
	101, 9, 10, 43, 45, 48, 57, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	44, 46, 9, 10, 43, 45, 48, 57, 
	13, 32, 44, 46, 69, 101, 9, 10, 
	43, 45, 48, 57, 111, 116, 97, 116, 
	101, 13, 32, 40, 9, 10, 13, 32, 
	43, 45, 46, 9, 10, 48, 57, 46, 
	48, 57, 48, 57, 13, 32, 41, 44, 
	46, 69, 101, 9, 10, 43, 45, 48, 
	57, 13, 32, 41, 44, 46, 9, 10, 
	43, 45, 48, 57, 46, 48, 57, 48, 
	57, 13, 32, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 13, 32, 44, 
	46, 9, 10, 43, 45, 48, 57, 46, 
	48, 57, 48, 57, 13, 32, 41, 69, 
	101, 9, 10, 48, 57, 13, 32, 41, 
	9, 10, 43, 45, 48, 57, 48, 57, 
	13, 32, 41, 9, 10, 48, 57, 13, 
	32, 41, 46, 69, 101, 9, 10, 48, 
	57, 13, 32, 43, 45, 46, 9, 10, 
	48, 57, 43, 45, 48, 57, 48, 57, 
	13, 32, 44, 46, 9, 10, 43, 45, 
	48, 57, 13, 32, 44, 46, 69, 101, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	43, 45, 46, 9, 10, 48, 57, 43, 
	45, 48, 57, 48, 57, 13, 32, 41, 
	44, 46, 9, 10, 43, 45, 48, 57, 
	13, 32, 41, 44, 46, 69, 101, 9, 
	10, 43, 45, 48, 57, 99, 107, 97, 
	108, 101, 13, 32, 40, 9, 10, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	46, 48, 57, 48, 57, 13, 32, 41, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 13, 32, 41, 44, 46, 9, 
	10, 43, 45, 48, 57, 46, 48, 57, 
	48, 57, 13, 32, 41, 69, 101, 9, 
	10, 48, 57, 13, 32, 41, 9, 10, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	41, 9, 10, 48, 57, 13, 32, 41, 
	46, 69, 101, 9, 10, 48, 57, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	41, 44, 46, 9, 10, 43, 45, 48, 
	57, 13, 32, 41, 44, 46, 69, 101, 
	9, 10, 43, 45, 48, 57, 101, 119, 
	88, 89, 13, 32, 40, 9, 10, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	46, 48, 57, 48, 57, 13, 32, 41, 
	69, 101, 9, 10, 48, 57, 13, 32, 
	41, 9, 10, 43, 45, 48, 57, 48, 
	57, 13, 32, 41, 9, 10, 48, 57, 
	13, 32, 41, 46, 69, 101, 9, 10, 
	48, 57, 13, 32, 40, 9, 10, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	46, 48, 57, 48, 57, 13, 32, 41, 
	69, 101, 9, 10, 48, 57, 13, 32, 
	41, 9, 10, 43, 45, 48, 57, 48, 
	57, 13, 32, 41, 9, 10, 48, 57, 
	13, 32, 41, 46, 69, 101, 9, 10, 
	48, 57, 114, 97, 110, 115, 108, 97, 
	116, 101, 13, 32, 40, 9, 10, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	46, 48, 57, 48, 57, 13, 32, 41, 
	44, 46, 69, 101, 9, 10, 43, 45, 
	48, 57, 13, 32, 41, 44, 46, 9, 
	10, 43, 45, 48, 57, 46, 48, 57, 
	48, 57, 13, 32, 41, 69, 101, 9, 
	10, 48, 57, 13, 32, 41, 9, 10, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	41, 9, 10, 48, 57, 13, 32, 41, 
	46, 69, 101, 9, 10, 48, 57, 13, 
	32, 43, 45, 46, 9, 10, 48, 57, 
	43, 45, 48, 57, 48, 57, 13, 32, 
	41, 44, 46, 9, 10, 43, 45, 48, 
	57, 13, 32, 41, 44, 46, 69, 101, 
	9, 10, 43, 45, 48, 57, 13, 32, 
	109, 114, 115, 116, 9, 10, 13, 32, 
	109, 114, 115, 116, 9, 10, 13, 32, 
	44, 9, 10, 13, 32, 44, 109, 114, 
	115, 116, 9, 10, 13, 32, 44, 9, 
	10, 13, 32, 44, 9, 10, 13, 32, 
	44, 9, 10, 13, 32, 44, 9, 10, 
	13, 32, 44, 9, 10, 0
};

static const char _svg_transform_single_lengths[] = {
	0, 1, 1, 1, 1, 1, 3, 5, 
	1, 0, 6, 4, 1, 0, 6, 4, 
	1, 0, 6, 4, 1, 0, 6, 4, 
	1, 0, 6, 4, 1, 0, 5, 3, 
	6, 1, 1, 1, 1, 1, 3, 5, 
	1, 0, 6, 4, 1, 0, 6, 4, 
	1, 0, 6, 4, 1, 0, 6, 4, 
	1, 0, 6, 4, 1, 0, 5, 3, 
	2, 0, 3, 6, 5, 2, 0, 4, 
	6, 5, 2, 0, 4, 6, 5, 2, 
	0, 4, 6, 5, 2, 0, 4, 6, 
	5, 2, 0, 4, 6, 1, 1, 1, 
	1, 1, 3, 5, 1, 0, 7, 5, 
	1, 0, 6, 4, 1, 0, 5, 3, 
	2, 0, 3, 6, 5, 2, 0, 4, 
	6, 5, 2, 0, 5, 7, 2, 1, 
	1, 1, 3, 5, 1, 0, 7, 5, 
	1, 0, 5, 3, 2, 0, 3, 6, 
	5, 2, 0, 5, 7, 1, 1, 2, 
	3, 5, 1, 0, 5, 3, 2, 0, 
	3, 6, 3, 5, 1, 0, 5, 3, 
	2, 0, 3, 6, 1, 1, 1, 1, 
	1, 1, 1, 1, 3, 5, 1, 0, 
	7, 5, 1, 0, 5, 3, 2, 0, 
	3, 6, 5, 2, 0, 5, 7, 2, 
	0, 3, 6, 5, 2, 0, 4, 6, 
	5, 2, 0, 4, 6, 5, 2, 0, 
	4, 6, 5, 2, 0, 4, 6, 5, 
	2, 0, 4, 6, 1, 1, 1, 1, 
	1, 3, 5, 1, 0, 7, 5, 1, 
	0, 6, 4, 1, 0, 5, 3, 2, 
	0, 3, 6, 5, 2, 0, 4, 6, 
	5, 2, 0, 5, 7, 2, 1, 1, 
	1, 3, 5, 1, 0, 7, 5, 1, 
	0, 5, 3, 2, 0, 3, 6, 5, 
	2, 0, 5, 7, 1, 1, 2, 3, 
	5, 1, 0, 5, 3, 2, 0, 3, 
	6, 3, 5, 1, 0, 5, 3, 2, 
	0, 3, 6, 1, 1, 1, 1, 1, 
	1, 1, 1, 3, 5, 1, 0, 7, 
	5, 1, 0, 5, 3, 2, 0, 3, 
	6, 5, 2, 0, 5, 7, 6, 6, 
	3, 7, 3, 3, 3, 3, 3
};

static const char _svg_transform_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 1, 2, 
	1, 1, 3, 3, 1, 1, 3, 3, 
	1, 1, 3, 3, 1, 1, 3, 3, 
	1, 1, 3, 3, 1, 1, 2, 1, 
	1, 0, 0, 0, 0, 0, 1, 2, 
	1, 1, 3, 3, 1, 1, 3, 3, 
	1, 1, 3, 3, 1, 1, 3, 3, 
	1, 1, 3, 3, 1, 1, 2, 1, 
	1, 1, 2, 2, 2, 1, 1, 3, 
	3, 2, 1, 1, 3, 3, 2, 1, 
	1, 3, 3, 2, 1, 1, 3, 3, 
	2, 1, 1, 3, 3, 0, 0, 0, 
	0, 0, 1, 2, 1, 1, 3, 3, 
	1, 1, 3, 3, 1, 1, 2, 1, 
	1, 1, 2, 2, 2, 1, 1, 3, 
	3, 2, 1, 1, 3, 3, 0, 0, 
	0, 0, 1, 2, 1, 1, 3, 3, 
	1, 1, 2, 1, 1, 1, 2, 2, 
	2, 1, 1, 3, 3, 0, 0, 0, 
	1, 2, 1, 1, 2, 1, 1, 1, 
	2, 2, 1, 2, 1, 1, 2, 1, 
	1, 1, 2, 2, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 2, 1, 1, 
	3, 3, 1, 1, 2, 1, 1, 1, 
	2, 2, 2, 1, 1, 3, 3, 1, 
	1, 2, 2, 2, 1, 1, 3, 3, 
	2, 1, 1, 3, 3, 2, 1, 1, 
	3, 3, 2, 1, 1, 3, 3, 2, 
	1, 1, 3, 3, 0, 0, 0, 0, 
	0, 1, 2, 1, 1, 3, 3, 1, 
	1, 3, 3, 1, 1, 2, 1, 1, 
	1, 2, 2, 2, 1, 1, 3, 3, 
	2, 1, 1, 3, 3, 0, 0, 0, 
	0, 1, 2, 1, 1, 3, 3, 1, 
	1, 2, 1, 1, 1, 2, 2, 2, 
	1, 1, 3, 3, 0, 0, 0, 1, 
	2, 1, 1, 2, 1, 1, 1, 2, 
	2, 1, 2, 1, 1, 2, 1, 1, 
	1, 2, 2, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 2, 1, 1, 3, 
	3, 1, 1, 2, 1, 1, 1, 2, 
	2, 2, 1, 1, 3, 3, 1, 1, 
	1, 1, 1, 1, 1, 1, 1
};

static const short _svg_transform_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 15, 
	23, 26, 28, 38, 46, 49, 51, 61, 
	69, 72, 74, 84, 92, 95, 97, 107, 
	115, 118, 120, 130, 138, 141, 143, 151, 
	156, 164, 166, 168, 170, 172, 174, 179, 
	187, 190, 192, 202, 210, 213, 215, 225, 
	233, 236, 238, 248, 256, 259, 261, 271, 
	279, 282, 284, 294, 302, 305, 307, 315, 
	320, 324, 326, 332, 341, 349, 353, 355, 
	363, 373, 381, 385, 387, 395, 405, 413, 
	417, 419, 427, 437, 445, 449, 451, 459, 
	469, 477, 481, 483, 491, 501, 503, 505, 
	507, 509, 511, 516, 524, 527, 529, 540, 
	549, 552, 554, 564, 572, 575, 577, 585, 
	590, 594, 596, 602, 611, 619, 623, 625, 
	633, 643, 651, 655, 657, 666, 677, 680, 
	682, 684, 686, 691, 699, 702, 704, 715, 
	724, 727, 729, 737, 742, 746, 748, 754, 
	763, 771, 775, 777, 786, 797, 799, 801, 
	804, 809, 817, 820, 822, 830, 835, 839, 
	841, 847, 856, 861, 869, 872, 874, 882, 
	887, 891, 893, 899, 908, 910, 912, 914, 
	916, 918, 920, 922, 924, 929, 937, 940, 
	942, 953, 962, 965, 967, 975, 980, 984, 
	986, 992, 1001, 1009, 1013, 1015, 1024, 1035, 
	1039, 1041, 1047, 1056, 1064, 1068, 1070, 1078, 
	1088, 1096, 1100, 1102, 1110, 1120, 1128, 1132, 
	1134, 1142, 1152, 1160, 1164, 1166, 1174, 1184, 
	1192, 1196, 1198, 1206, 1216, 1218, 1220, 1222, 
	1224, 1226, 1231, 1239, 1242, 1244, 1255, 1264, 
	1267, 1269, 1279, 1287, 1290, 1292, 1300, 1305, 
	1309, 1311, 1317, 1326, 1334, 1338, 1340, 1348, 
	1358, 1366, 1370, 1372, 1381, 1392, 1395, 1397, 
	1399, 1401, 1406, 1414, 1417, 1419, 1430, 1439, 
	1442, 1444, 1452, 1457, 1461, 1463, 1469, 1478, 
	1486, 1490, 1492, 1501, 1512, 1514, 1516, 1519, 
	1524, 1532, 1535, 1537, 1545, 1550, 1554, 1556, 
	1562, 1571, 1576, 1584, 1587, 1589, 1597, 1602, 
	1606, 1608, 1614, 1623, 1625, 1627, 1629, 1631, 
	1633, 1635, 1637, 1639, 1644, 1652, 1655, 1657, 
	1668, 1677, 1680, 1682, 1690, 1695, 1699, 1701, 
	1707, 1716, 1724, 1728, 1730, 1739, 1750, 1758, 
	1766, 1771, 1780, 1785, 1790, 1795, 1800
};

static const short _svg_transform_indicies[] = {
	1, 0, 2, 0, 3, 0, 4, 0, 
	5, 0, 5, 5, 6, 5, 0, 6, 
	6, 7, 7, 8, 6, 9, 0, 10, 
	11, 0, 12, 0, 13, 13, 15, 16, 
	17, 17, 13, 14, 12, 0, 18, 18, 
	20, 21, 18, 19, 22, 0, 23, 24, 
	0, 25, 0, 26, 26, 28, 29, 30, 
	30, 26, 27, 25, 0, 31, 31, 33, 
	34, 31, 32, 35, 0, 36, 37, 0, 
	38, 0, 39, 39, 41, 42, 43, 43, 
	39, 40, 38, 0, 44, 44, 46, 47, 
	44, 45, 48, 0, 49, 50, 0, 51, 
	0, 52, 52, 54, 55, 56, 56, 52, 
	53, 51, 0, 57, 57, 59, 60, 57, 
	58, 61, 0, 62, 63, 0, 64, 0, 
	65, 65, 67, 68, 69, 69, 65, 66, 
	64, 0, 70, 70, 72, 73, 70, 71, 
	74, 0, 75, 76, 0, 77, 0, 78, 
	78, 79, 80, 80, 78, 77, 0, 81, 
	81, 82, 81, 0, 84, 84, 85, 86, 
	87, 88, 84, 83, 89, 83, 90, 83, 
	91, 83, 92, 83, 93, 83, 93, 93, 
	94, 93, 83, 94, 94, 95, 95, 96, 
	94, 97, 83, 98, 99, 83, 100, 83, 
	101, 101, 103, 104, 105, 105, 101, 102, 
	100, 83, 106, 106, 108, 109, 106, 107, 
	110, 83, 111, 112, 83, 113, 83, 114, 
	114, 116, 117, 118, 118, 114, 115, 113, 
	83, 119, 119, 121, 122, 119, 120, 123, 
	83, 124, 125, 83, 126, 83, 127, 127, 
	129, 130, 131, 131, 127, 128, 126, 83, 
	132, 132, 134, 135, 132, 133, 136, 83, 
	137, 138, 83, 139, 83, 140, 140, 142, 
	143, 144, 144, 140, 141, 139, 83, 145, 
	145, 147, 148, 145, 146, 149, 83, 150, 
	151, 83, 152, 83, 153, 153, 155, 156, 
	157, 157, 153, 154, 152, 83, 158, 158, 
	160, 161, 158, 159, 162, 83, 163, 164, 
	83, 165, 83, 166, 166, 79, 167, 167, 
	166, 165, 83, 168, 168, 82, 168, 83, 
	169, 169, 170, 83, 170, 83, 166, 166, 
	79, 166, 170, 83, 166, 166, 79, 165, 
	167, 167, 166, 164, 83, 160, 160, 159, 
	159, 161, 160, 162, 83, 171, 171, 172, 
	83, 172, 83, 153, 153, 155, 156, 153, 
	154, 172, 83, 153, 153, 155, 152, 157, 
	157, 153, 154, 151, 83, 147, 147, 146, 
	146, 148, 147, 149, 83, 173, 173, 174, 
	83, 174, 83, 140, 140, 142, 143, 140, 
	141, 174, 83, 140, 140, 142, 139, 144, 
	144, 140, 141, 138, 83, 134, 134, 133, 
	133, 135, 134, 136, 83, 175, 175, 176, 
	83, 176, 83, 127, 127, 129, 130, 127, 
	128, 176, 83, 127, 127, 129, 126, 131, 
	131, 127, 128, 125, 83, 121, 121, 120, 
	120, 122, 121, 123, 83, 177, 177, 178, 
	83, 178, 83, 114, 114, 116, 117, 114, 
	115, 178, 83, 114, 114, 116, 113, 118, 
	118, 114, 115, 112, 83, 108, 108, 107, 
	107, 109, 108, 110, 83, 179, 179, 180, 
	83, 180, 83, 101, 101, 103, 104, 101, 
	102, 180, 83, 101, 101, 103, 100, 105, 
	105, 101, 102, 99, 83, 181, 83, 182, 
	83, 183, 83, 184, 83, 185, 83, 185, 
	185, 186, 185, 83, 186, 186, 187, 187, 
	188, 186, 189, 83, 190, 191, 83, 192, 
	83, 193, 193, 194, 196, 197, 198, 198, 
	193, 195, 192, 83, 199, 199, 200, 202, 
	203, 199, 201, 204, 83, 205, 206, 83, 
	207, 83, 208, 208, 210, 211, 212, 212, 
	208, 209, 207, 83, 213, 213, 215, 216, 
	213, 214, 217, 83, 218, 219, 83, 220, 
	83, 221, 221, 194, 222, 222, 221, 220, 
	83, 223, 223, 200, 223, 83, 224, 224, 
	225, 83, 225, 83, 221, 221, 194, 221, 
	225, 83, 221, 221, 194, 220, 222, 222, 
	221, 219, 83, 215, 215, 214, 214, 216, 
	215, 217, 83, 226, 226, 227, 83, 227, 
	83, 208, 208, 210, 211, 208, 209, 227, 
	83, 208, 208, 210, 207, 212, 212, 208, 
	209, 206, 83, 202, 202, 201, 201, 203, 
	202, 204, 83, 228, 228, 229, 83, 229, 
	83, 193, 193, 194, 196, 197, 193, 195, 
	229, 83, 193, 193, 194, 196, 192, 198, 
	198, 193, 195, 191, 83, 230, 231, 83, 
	232, 83, 233, 83, 234, 83, 234, 234, 
	235, 234, 83, 235, 235, 236, 236, 237, 
	235, 238, 83, 239, 240, 83, 241, 83, 
	242, 242, 243, 245, 246, 247, 247, 242, 
	244, 241, 83, 248, 248, 249, 251, 252, 
	248, 250, 253, 83, 254, 255, 83, 256, 
	83, 257, 257, 243, 258, 258, 257, 256, 
	83, 259, 259, 249, 259, 83, 260, 260, 
	261, 83, 261, 83, 257, 257, 243, 257, 
	261, 83, 257, 257, 243, 256, 258, 258, 
	257, 255, 83, 251, 251, 250, 250, 252, 
	251, 253, 83, 262, 262, 263, 83, 263, 
	83, 242, 242, 243, 245, 246, 242, 244, 
	263, 83, 242, 242, 243, 245, 241, 247, 
	247, 242, 244, 240, 83, 264, 83, 265, 
	83, 266, 267, 83, 266, 266, 268, 266, 
	83, 268, 268, 269, 269, 270, 268, 271, 
	83, 272, 273, 83, 274, 83, 275, 275, 
	276, 277, 277, 275, 274, 83, 278, 278, 
	279, 278, 83, 280, 280, 281, 83, 281, 
	83, 275, 275, 276, 275, 281, 83, 275, 
	275, 276, 274, 277, 277, 275, 273, 83, 
	267, 267, 282, 267, 83, 282, 282, 283, 
	283, 284, 282, 285, 83, 286, 287, 83, 
	288, 83, 289, 289, 290, 291, 291, 289, 
	288, 83, 292, 292, 293, 292, 83, 294, 
	294, 295, 83, 295, 83, 289, 289, 290, 
	289, 295, 83, 289, 289, 290, 288, 291, 
	291, 289, 287, 83, 296, 83, 297, 83, 
	298, 83, 299, 83, 300, 83, 301, 83, 
	302, 83, 303, 83, 303, 303, 304, 303, 
	83, 304, 304, 305, 305, 306, 304, 307, 
	83, 308, 309, 83, 310, 83, 311, 311, 
	312, 314, 315, 316, 316, 311, 313, 310, 
	83, 317, 317, 318, 320, 321, 317, 319, 
	322, 83, 323, 324, 83, 325, 83, 326, 
	326, 312, 327, 327, 326, 325, 83, 328, 
	328, 318, 328, 83, 329, 329, 330, 83, 
	330, 83, 326, 326, 312, 326, 330, 83, 
	326, 326, 312, 325, 327, 327, 326, 324, 
	83, 320, 320, 319, 319, 321, 320, 322, 
	83, 331, 331, 332, 83, 332, 83, 311, 
	311, 312, 314, 315, 311, 313, 332, 83, 
	311, 311, 312, 314, 310, 316, 316, 311, 
	313, 309, 83, 333, 333, 334, 0, 334, 
	0, 78, 78, 79, 78, 334, 0, 78, 
	78, 79, 77, 80, 80, 78, 76, 0, 
	72, 72, 71, 71, 73, 72, 74, 0, 
	335, 335, 336, 0, 336, 0, 65, 65, 
	67, 68, 65, 66, 336, 0, 65, 65, 
	67, 64, 69, 69, 65, 66, 63, 0, 
	59, 59, 58, 58, 60, 59, 61, 0, 
	337, 337, 338, 0, 338, 0, 52, 52, 
	54, 55, 52, 53, 338, 0, 52, 52, 
	54, 51, 56, 56, 52, 53, 50, 0, 
	46, 46, 45, 45, 47, 46, 48, 0, 
	339, 339, 340, 0, 340, 0, 39, 39, 
	41, 42, 39, 40, 340, 0, 39, 39, 
	41, 38, 43, 43, 39, 40, 37, 0, 
	33, 33, 32, 32, 34, 33, 35, 0, 
	341, 341, 342, 0, 342, 0, 26, 26, 
	28, 29, 26, 27, 342, 0, 26, 26, 
	28, 25, 30, 30, 26, 27, 24, 0, 
	20, 20, 19, 19, 21, 20, 22, 0, 
	343, 343, 344, 0, 344, 0, 13, 13, 
	15, 16, 13, 14, 344, 0, 13, 13, 
	15, 12, 17, 17, 13, 14, 11, 0, 
	345, 0, 346, 0, 347, 0, 348, 0, 
	349, 0, 349, 349, 350, 349, 0, 350, 
	350, 351, 351, 352, 350, 353, 0, 354, 
	355, 0, 356, 0, 357, 357, 194, 359, 
	360, 361, 361, 357, 358, 356, 0, 362, 
	362, 200, 364, 365, 362, 363, 366, 0, 
	367, 368, 0, 369, 0, 370, 370, 372, 
	373, 374, 374, 370, 371, 369, 0, 375, 
	375, 377, 378, 375, 376, 379, 0, 380, 
	381, 0, 382, 0, 383, 383, 194, 384, 
	384, 383, 382, 0, 385, 385, 200, 385, 
	0, 386, 386, 387, 0, 387, 0, 383, 
	383, 194, 383, 387, 0, 383, 383, 194, 
	382, 384, 384, 383, 381, 0, 377, 377, 
	376, 376, 378, 377, 379, 0, 388, 388, 
	389, 0, 389, 0, 370, 370, 372, 373, 
	370, 371, 389, 0, 370, 370, 372, 369, 
	374, 374, 370, 371, 368, 0, 364, 364, 
	363, 363, 365, 364, 366, 0, 390, 390, 
	391, 0, 391, 0, 357, 357, 194, 359, 
	360, 357, 358, 391, 0, 357, 357, 194, 
	359, 356, 361, 361, 357, 358, 355, 0, 
	392, 393, 0, 394, 0, 395, 0, 396, 
	0, 396, 396, 397, 396, 0, 397, 397, 
	398, 398, 399, 397, 400, 0, 401, 402, 
	0, 403, 0, 404, 404, 243, 406, 407, 
	408, 408, 404, 405, 403, 0, 409, 409, 
	249, 411, 412, 409, 410, 413, 0, 414, 
	415, 0, 416, 0, 417, 417, 243, 418, 
	418, 417, 416, 0, 419, 419, 249, 419, 
	0, 420, 420, 421, 0, 421, 0, 417, 
	417, 243, 417, 421, 0, 417, 417, 243, 
	416, 418, 418, 417, 415, 0, 411, 411, 
	410, 410, 412, 411, 413, 0, 422, 422, 
	423, 0, 423, 0, 404, 404, 243, 406, 
	407, 404, 405, 423, 0, 404, 404, 243, 
	406, 403, 408, 408, 404, 405, 402, 0, 
	424, 0, 425, 0, 426, 427, 0, 426, 
	426, 428, 426, 0, 428, 428, 429, 429, 
	430, 428, 431, 0, 432, 433, 0, 434, 
	0, 435, 435, 276, 436, 436, 435, 434, 
	0, 437, 437, 279, 437, 0, 438, 438, 
	439, 0, 439, 0, 435, 435, 276, 435, 
	439, 0, 435, 435, 276, 434, 436, 436, 
	435, 433, 0, 427, 427, 440, 427, 0, 
	440, 440, 441, 441, 442, 440, 443, 0, 
	444, 445, 0, 446, 0, 447, 447, 290, 
	448, 448, 447, 446, 0, 449, 449, 293, 
	449, 0, 450, 450, 451, 0, 451, 0, 
	447, 447, 290, 447, 451, 0, 447, 447, 
	290, 446, 448, 448, 447, 445, 0, 452, 
	0, 453, 0, 454, 0, 455, 0, 456, 
	0, 457, 0, 458, 0, 459, 0, 459, 
	459, 460, 459, 0, 460, 460, 461, 461, 
	462, 460, 463, 0, 464, 465, 0, 466, 
	0, 467, 467, 312, 469, 470, 471, 471, 
	467, 468, 466, 0, 472, 472, 318, 474, 
	475, 472, 473, 476, 0, 477, 478, 0, 
	479, 0, 480, 480, 312, 481, 481, 480, 
	479, 0, 482, 482, 318, 482, 0, 483, 
	483, 484, 0, 484, 0, 480, 480, 312, 
	480, 484, 0, 480, 480, 312, 479, 481, 
	481, 480, 478, 0, 474, 474, 473, 473, 
	475, 474, 476, 0, 485, 485, 486, 0, 
	486, 0, 467, 467, 312, 469, 470, 467, 
	468, 486, 0, 467, 467, 312, 469, 466, 
	471, 471, 467, 468, 465, 0, 487, 487, 
	489, 490, 491, 492, 487, 488, 487, 487, 
	489, 490, 491, 492, 487, 0, 494, 494, 
	495, 494, 493, 497, 497, 84, 85, 86, 
	87, 88, 497, 496, 499, 499, 500, 499, 
	498, 502, 502, 503, 502, 501, 505, 505, 
	506, 505, 504, 508, 508, 509, 508, 507, 
	511, 511, 512, 511, 510, 0
};

static const short _svg_transform_trans_targs[] = {
	334, 2, 3, 4, 5, 6, 7, 8, 
	9, 227, 9, 227, 10, 11, 12, 223, 
	13, 224, 11, 12, 223, 13, 222, 13, 
	222, 14, 15, 16, 218, 17, 219, 15, 
	16, 218, 17, 217, 17, 217, 18, 19, 
	20, 213, 21, 214, 19, 20, 213, 21, 
	212, 21, 212, 22, 23, 24, 208, 25, 
	209, 23, 24, 208, 25, 207, 25, 207, 
	26, 27, 28, 203, 29, 204, 27, 28, 
	203, 29, 202, 29, 202, 30, 31, 336, 
	199, 31, 336, 334, 32, 33, 93, 126, 
	172, 34, 35, 36, 37, 38, 39, 40, 
	41, 92, 41, 92, 42, 43, 44, 88, 
	45, 89, 43, 44, 88, 45, 87, 45, 
	87, 46, 47, 48, 83, 49, 84, 47, 
	48, 83, 49, 82, 49, 82, 50, 51, 
	52, 78, 53, 79, 51, 52, 78, 53, 
	77, 53, 77, 54, 55, 56, 73, 57, 
	74, 55, 56, 73, 57, 72, 57, 72, 
	58, 59, 60, 68, 61, 69, 59, 60, 
	68, 61, 67, 61, 67, 62, 63, 64, 
	63, 65, 66, 70, 71, 75, 76, 80, 
	81, 85, 86, 90, 91, 94, 95, 96, 
	97, 98, 99, 100, 101, 125, 101, 125, 
	102, 103, 338, 104, 121, 105, 122, 103, 
	338, 104, 121, 105, 120, 105, 120, 106, 
	107, 108, 116, 109, 117, 107, 108, 116, 
	109, 115, 109, 115, 110, 111, 112, 111, 
	113, 114, 118, 119, 123, 124, 127, 149, 
	128, 129, 130, 131, 132, 133, 148, 133, 
	148, 134, 135, 339, 136, 144, 137, 145, 
	135, 339, 136, 144, 137, 143, 137, 143, 
	138, 139, 140, 139, 141, 142, 146, 147, 
	150, 151, 152, 162, 153, 154, 155, 161, 
	155, 161, 156, 157, 340, 158, 157, 340, 
	159, 160, 163, 164, 165, 171, 165, 171, 
	166, 167, 341, 168, 167, 341, 169, 170, 
	173, 174, 175, 176, 177, 178, 179, 180, 
	181, 182, 183, 198, 183, 198, 184, 185, 
	342, 186, 194, 187, 195, 185, 342, 186, 
	194, 187, 193, 187, 193, 188, 189, 190, 
	189, 191, 192, 196, 197, 200, 201, 205, 
	206, 210, 211, 215, 216, 220, 221, 225, 
	226, 229, 230, 231, 232, 233, 234, 235, 
	236, 260, 236, 260, 237, 238, 239, 256, 
	240, 257, 238, 239, 256, 240, 255, 240, 
	255, 241, 242, 243, 251, 244, 252, 242, 
	243, 251, 244, 250, 244, 250, 245, 246, 
	247, 246, 248, 249, 253, 254, 258, 259, 
	262, 284, 263, 264, 265, 266, 267, 268, 
	283, 268, 283, 269, 270, 271, 279, 272, 
	280, 270, 271, 279, 272, 278, 272, 278, 
	273, 274, 275, 274, 276, 277, 281, 282, 
	285, 286, 287, 297, 288, 289, 290, 296, 
	290, 296, 291, 292, 293, 292, 294, 295, 
	298, 299, 300, 306, 300, 306, 301, 302, 
	303, 302, 304, 305, 308, 309, 310, 311, 
	312, 313, 314, 315, 316, 317, 318, 333, 
	318, 333, 319, 320, 321, 329, 322, 330, 
	320, 321, 329, 322, 328, 322, 328, 323, 
	324, 325, 324, 326, 327, 331, 332, 335, 
	0, 1, 228, 261, 307, 334, 337, 32, 
	334, 337, 334, 337, 32, 334, 337, 32, 
	334, 337, 32, 334, 337, 32, 334, 337, 
	32
};

static const char _svg_transform_trans_actions[] = {
	13, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 0, 1, 15, 1, 
	15, 0, 0, 3, 0, 3, 3, 0, 
	0, 0, 1, 15, 1, 15, 0, 0, 
	3, 0, 3, 3, 0, 0, 0, 1, 
	15, 1, 15, 0, 0, 3, 0, 3, 
	3, 0, 0, 0, 1, 15, 1, 15, 
	0, 0, 3, 0, 3, 3, 0, 0, 
	0, 1, 15, 1, 15, 0, 0, 3, 
	0, 3, 3, 0, 0, 0, 1, 39, 
	0, 0, 7, 11, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 0, 1, 15, 1, 
	15, 0, 0, 3, 0, 3, 3, 0, 
	0, 0, 1, 15, 1, 15, 0, 0, 
	3, 0, 3, 3, 0, 0, 0, 1, 
	15, 1, 15, 0, 0, 3, 0, 3, 
	3, 0, 0, 0, 1, 15, 1, 15, 
	0, 0, 3, 0, 3, 3, 0, 0, 
	0, 1, 15, 1, 15, 0, 0, 3, 
	0, 3, 3, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	0, 1, 39, 15, 1, 15, 0, 0, 
	7, 3, 0, 3, 3, 0, 0, 0, 
	1, 15, 1, 15, 0, 0, 3, 0, 
	3, 3, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 0, 1, 39, 15, 1, 15, 0, 
	0, 7, 3, 0, 3, 3, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 0, 1, 39, 0, 0, 7, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	0, 1, 39, 0, 0, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 0, 1, 
	39, 15, 1, 15, 0, 0, 7, 3, 
	0, 3, 3, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 0, 1, 15, 1, 
	15, 0, 0, 3, 0, 3, 3, 0, 
	0, 0, 1, 15, 1, 15, 0, 0, 
	3, 0, 3, 3, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 1, 15, 1, 15, 
	0, 0, 3, 0, 3, 3, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 0, 1, 15, 1, 15, 0, 
	0, 3, 0, 3, 3, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 42, 
	0, 0, 0, 0, 0, 65, 89, 33, 
	9, 7, 53, 77, 24, 49, 73, 21, 
	57, 81, 27, 61, 85, 30, 45, 69, 
	18
};

static const char _svg_transform_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 36, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const char _svg_transform_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 5, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const short _svg_transform_eof_trans[] = {
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 84, 
	84, 84, 84, 84, 84, 84, 84, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	494, 497, 499, 502, 505, 508, 511
};

static const int svg_transform_start = 334;
static const int svg_transform_first_final = 334;

static const int svg_transform_en_main = 334;


#line 28 "svg-affine-parser.rl"


// https://www.w3.org/TR/css-transforms-1/#svg-syntax
bool sp_svg_transform_read(gchar const *str, Geom::Affine *transform)
{

    std::vector<double> params;
    Geom::Affine final_transform (Geom::identity());
    Geom::Affine tmp_transform (Geom::identity());
    int cs;
    const char *p = str;
    const char *pe = p + strlen(p) + 1;
    const char *eof = pe;
    char const *start_num = 0;
    char const *ts = p;
    char const *te = pe;
    int act = 0;


#line 1007 "svg-affine-parser.cpp"
	{
	cs = svg_transform_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 1015 "svg-affine-parser.cpp"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _svg_transform_actions + _svg_transform_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 11:
#line 1 "NONE"
	{ts = p;}
	break;
#line 1036 "svg-affine-parser.cpp"
		}
	}

	_keys = _svg_transform_trans_keys + _svg_transform_key_offsets[cs];
	_trans = _svg_transform_index_offsets[cs];

	_klen = _svg_transform_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _svg_transform_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _svg_transform_indicies[_trans];
_eof_trans:
	cs = _svg_transform_trans_targs[_trans];

	if ( _svg_transform_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _svg_transform_actions + _svg_transform_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 49 "svg-affine-parser.rl"
	{
      std::string buf(start_num, p); 
      params.push_back(g_ascii_strtod(buf.c_str(), NULL));
    }
	break;
	case 1:
#line 54 "svg-affine-parser.rl"
	{ tmp_transform = Geom::Translate(params[0], params.size() == 1 ? 0 : params[1]); }
	break;
	case 2:
#line 55 "svg-affine-parser.rl"
	{ tmp_transform = Geom::Scale(params[0], params.size() == 1 ? params[0] : params[1]); }
	break;
	case 3:
#line 56 "svg-affine-parser.rl"
	{
        if (params.size() == 1) 
            tmp_transform = Geom::Rotate(Geom::rad_from_deg(params[0])); 
        else {
            tmp_transform = Geom::Translate(-params[1], -params[2]) * 
                            Geom::Rotate(Geom::rad_from_deg(params[0])) * 
                            Geom::Translate(params[1], params[2]); 
        } 
    }
	break;
	case 4:
#line 65 "svg-affine-parser.rl"
	{ tmp_transform = Geom::Affine(1, 0, tan(params[0] * M_PI / 180.0), 1, 0, 0); }
	break;
	case 5:
#line 66 "svg-affine-parser.rl"
	{ tmp_transform = Geom::Affine(1, tan(params[0] * M_PI / 180.0), 0, 1, 0, 0); }
	break;
	case 6:
#line 67 "svg-affine-parser.rl"
	{ tmp_transform = Geom::Affine(params[0], params[1], params[2], params[3], params[4], params[5]);}
	break;
	case 7:
#line 68 "svg-affine-parser.rl"
	{params.clear(); final_transform = tmp_transform * final_transform ;}
	break;
	case 8:
#line 82 "svg-affine-parser.rl"
	{start_num = p;}
	break;
	case 12:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 13:
#line 69 "svg-affine-parser.rl"
	{act = 1;}
	break;
	case 14:
#line 69 "svg-affine-parser.rl"
	{te = p;p--;{ *transform = final_transform; return true;}}
	break;
	case 15:
#line 69 "svg-affine-parser.rl"
	{{p = ((te))-1;}{ *transform = final_transform; return true;}}
	break;
	case 16:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{cs = 0;goto _again;}}
	break;
	case 1:
	{{p = ((te))-1;} *transform = final_transform; return true;}
	break;
	}
	}
	break;
#line 1177 "svg-affine-parser.cpp"
		}
	}

_again:
	_acts = _svg_transform_actions + _svg_transform_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 9:
#line 1 "NONE"
	{ts = 0;}
	break;
	case 10:
#line 1 "NONE"
	{act = 0;}
	break;
#line 1194 "svg-affine-parser.cpp"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _svg_transform_eof_trans[cs] > 0 ) {
		_trans = _svg_transform_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 112 "svg-affine-parser.rl"

    g_warning("could not parse transform attribute");

    return false;
}

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=ragel:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:fileencoding=utf-8:textwidth=99 :
