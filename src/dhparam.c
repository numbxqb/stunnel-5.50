#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
#ifndef HEADER_DH_H
# include <openssl/dh.h>
#endif

DH *get_dh2048()
{
    static unsigned char dhp_2048[] = {
	0x96, 0xB4, 0xED, 0x78, 0xAF, 0xD4, 0xDD, 0xBF, 0x55, 0xDB, 
	0xAD, 0x85, 0xA0, 0x5C, 0x22, 0xC3, 0x8C, 0x14, 0x79, 0xE5, 
	0x0A, 0xB1, 0x48, 0xAC, 0x22, 0x77, 0xDA, 0x86, 0x57, 0xCF, 
	0x3C, 0xEC, 0x12, 0xD2, 0x28, 0x41, 0x7A, 0xCD, 0xD0, 0x55, 
	0x1B, 0x80, 0xEB, 0x9E, 0x60, 0xFA, 0x36, 0x7B, 0xB0, 0x33, 
	0x2A, 0xD3, 0x32, 0xD3, 0x19, 0xB6, 0x51, 0x26, 0x4C, 0x6F, 
	0x62, 0xE5, 0x90, 0x32, 0x75, 0xEB, 0x85, 0x6E, 0x4E, 0x0A, 
	0xC5, 0x1E, 0x16, 0x73, 0x00, 0xB0, 0xB3, 0x46, 0xCA, 0x9D, 
	0xD9, 0xD2, 0x72, 0x43, 0xBB, 0xDB, 0xED, 0x82, 0xDF, 0xD7, 
	0x6E, 0x61, 0x65, 0x62, 0x73, 0x27, 0x0E, 0xD6, 0x92, 0x4E, 
	0x7F, 0x11, 0x7A, 0xDE, 0x8E, 0x3A, 0xB6, 0x5C, 0x67, 0x73, 
	0xD0, 0x5D, 0xC6, 0xC8, 0x86, 0x01, 0xAA, 0x93, 0x19, 0x7E, 
	0x59, 0xDE, 0xEB, 0x51, 0x83, 0x10, 0x76, 0x46, 0x50, 0x60, 
	0xEE, 0xBD, 0x6F, 0xB3, 0x6F, 0x6A, 0x0D, 0x9C, 0x4E, 0x4D, 
	0xB8, 0x51, 0x89, 0x8D, 0x4C, 0x15, 0xCD, 0x91, 0x01, 0x13, 
	0x3C, 0x79, 0x57, 0x0A, 0x17, 0x33, 0x68, 0x85, 0x71, 0xA3, 
	0xF9, 0x7C, 0x22, 0x91, 0x7E, 0x75, 0xB1, 0x7B, 0x60, 0x33, 
	0x84, 0xFB, 0xB2, 0x42, 0x4D, 0x51, 0x6F, 0x2C, 0x41, 0xD6, 
	0xC4, 0x5E, 0x3A, 0xFF, 0x49, 0x93, 0x8A, 0xEE, 0xCC, 0x2A, 
	0xCB, 0x0F, 0x1C, 0x17, 0x85, 0x57, 0x2F, 0x65, 0xC3, 0x54, 
	0x1F, 0xE0, 0x98, 0x1C, 0x2F, 0x3D, 0x67, 0xA1, 0x53, 0x67, 
	0xD7, 0xFC, 0xAC, 0x31, 0x68, 0xBF, 0x43, 0x71, 0xA7, 0xBF, 
	0xE5, 0x1F, 0x9D, 0xD9, 0x72, 0x74, 0xD6, 0x92, 0x1D, 0x36, 
	0x1B, 0xBC, 0x49, 0x09, 0x84, 0x06, 0xC8, 0x4B, 0xD9, 0xB7, 
	0x17, 0xF3, 0x2F, 0x82, 0x9F, 0x3F, 0x50, 0x51, 0x34, 0x25, 
	0x84, 0x1A, 0xC5, 0x75, 0x1C, 0x93
    };
    static unsigned char dhg_2048[] = {
	0x02
    };
    DH *dh = DH_new();
    BIGNUM *dhp_bn, *dhg_bn;

    if (dh == NULL)
        return NULL;
    dhp_bn = BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
    dhg_bn = BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
    if (dhp_bn == NULL || dhg_bn == NULL
            || !DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn)) {
        DH_free(dh);
        BN_free(dhp_bn);
        BN_free(dhg_bn);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */