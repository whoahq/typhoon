#include "tempest/random/CRandom.hpp"
#include "tempest/math/CMath.hpp"

const uint32_t gnoise32[] = {
    0x9927148E, 0x08C7AAFD, 0x1F3EE6D5, 0xDA55BBF6,
    0x6A4AA075, 0xFF97BDE8, 0x9FBC9BDE, 0x46A18A81,
    0x63E30B6E, 0x5D6C7A76, 0xCA69D388, 0x25B947C3,
    0x3FA2AB83, 0xBA7C41A6, 0x0195ACE5, 0xC109CF7E,
    0x717062D9, 0x0205DB8D, 0x54EF8724, 0x3037D4C6,
    0x7BCB1BD0, 0xECD8E4B8, 0xDCADCE49, 0xC494A913,
    0x0DAE398F, 0x0EDD5218, 0x85F5FA78, 0x6DAFD258,
    0x3B53B2A4, 0xBE50A551, 0x11F42DFC, 0xF1169848,
    0x663DDF86, 0x2F2E445E, 0x176B0736, 0xB64C298B,
    0xE75F89E2, 0xE121A7CD, 0xED65C94D, 0x239CEEFE,
    0x04B77D33, 0x402A9A9E, 0xF35B10B3, 0x921C7782,
    0x571E4E20, 0x8C067222, 0xFB732C67, 0xBF0AC259,
    0x0CF95C79, 0x68121A28, 0x42193474, 0xF884C0B1,
    0x9D15F038, 0x6F3AF260, 0x91EB90B4, 0x61357F1D,
    0x5603325A, 0x932BC5A3, 0x434B0F80, 0x3CE0A8F7,
    0x2664D196, 0x4FCC45D7, 0xB5E9B0C8, 0xEA31D600,
};

uint32_t CRandom::uint32(CRndSeed& seed) {
    auto acc = seed.rndacc;
    auto vls = seed.rndvls;

    uint8_t b1 = (vls >> 24) & 0xFF;
    uint8_t b2 = (vls >> 16) & 0xFF;
    uint8_t b3 = (vls >>  8) & 0xFF;
    uint8_t b4 = (vls >>  0) & 0xFF;

    int32_t r1 = b1 - 0x04 + (b1 - 0x04 < 0 ? 0xBC : 0);
    int32_t r2 = b2 - 0x0C + (b2 - 0x0C < 0 ? 0xD4 : 0);
    int32_t r3 = b3 - 0x18 + (b3 - 0x18 < 0 ? 0xEC : 0);
    int32_t r4 = b4 - 0x1C + (b4 - 0x1C < 0 ? 0xF4 : 0);

    auto noise = reinterpret_cast<const char*>(gnoise32);

    auto n1 = *reinterpret_cast<const uint32_t*>(&noise[r1]);
    auto n2 = *reinterpret_cast<const uint32_t*>(&noise[r2]);
    auto n3 = *reinterpret_cast<const uint32_t*>(&noise[r3]);
    auto n4 = *reinterpret_cast<const uint32_t*>(&noise[r4]);

    acc = (n4 ^ CMath::rotl3(n3) ^ CMath::rotl2(n2) ^ CMath::rotl1(n1)) + acc;

    seed.rndacc = acc;
    seed.rndvls = r4 | (r3 << 8) | ((r2 | (r1 << 8)) << 16);

    return acc;
}
