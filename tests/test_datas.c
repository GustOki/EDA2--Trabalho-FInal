#include "datas.h"
#include "testutil.h"
#include <string.h>

int main(void) {
    char iso[16];

    /* --- formato reuters: "Jul 18 2020" --- */
    CHECK(data_para_iso("Jul 18 2020", iso) == 1, "reuters: retorna sucesso");
    CHECK(strcmp(iso, "2020-07-18") == 0,          "reuters: Jul 18 2020 -> 2020-07-18");

    /* --- formato guardian: "18-Jul-20" (ano 2 dígitos) --- */
    CHECK(data_para_iso("18-Jul-20", iso) == 1,    "guardian: retorna sucesso");
    CHECK(strcmp(iso, "2020-07-18") == 0,          "guardian: 18-Jul-20 -> 2020-07-18");

    /* --- formato cnbc completo: ruído de hora + dia/mês/ano --- */
    CHECK(data_para_iso(" 7:51  PM ET Fri, 17 July 2020", iso) == 1,
          "cnbc: retorna sucesso");
    CHECK(strcmp(iso, "2020-07-17") == 0,
          "cnbc: '...17 July 2020' -> 2020-07-17");

    /* --- mês por extenso, dia antes --- */
    CHECK(data_para_iso("3 March 2024", iso) == 1, "extenso: sucesso");
    CHECK(strcmp(iso, "2024-03-03") == 0,          "extenso: 3 March 2024 -> 2024-03-03 (zero-pad)");

    /* --- nome de mês variando: dezembro --- */
    CHECK(data_para_iso("Dec 1 2019", iso) == 1,   "dez: sucesso");
    CHECK(strcmp(iso, "2019-12-01") == 0,          "dez: Dec 1 2019 -> 2019-12-01");

    /* --- entrada sem mês reconhecível: falha --- */
    CHECK(data_para_iso("sem data aqui 1234", iso) == 0, "sem mês: falha");
    CHECK(iso[0] == '\0',                                "falha limpa saída");

    /* --- entrada vazia: falha --- */
    CHECK(data_para_iso("", iso) == 0, "vazio: falha");

    TEST_SUMMARY();
}
