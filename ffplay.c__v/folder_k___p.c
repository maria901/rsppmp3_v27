
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                *
 *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
 *                                                                                *
 *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
 *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
 *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
 *   (dependendo da sua opção) qualquer versão posterior.                         *
 *                                                                                *
 *   Este programa é distribuído na esperança que isto vai ser útil,              *
 *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
 *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
 *   Licensa Geral Pública para mais detalhes.                                    *
 *                                                                                *
 *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
 *       e a GNU Licensa Pública Menor junto com este programa                    *
 *       Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                                *
 *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
 *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
 *             http://nomade.sourceforge.net/binarywork/ ______________            *
 *                                                                                *
 *       e-mails direto dos felizes programadores:                                *
 *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
 *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
 *                                                                                *
 *       contato imediato(para uma resposta muita rápida) WhatsApp                *
 *       (+55)41 9627 1708 - isto está sempre ligado                              *
 *                                                                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <stdbool.h>

#include <process.h>

#include "mv_from_AR.h"

/**
 * To print a printf based formatted system messagebox
 */
void mprintf(char *format, ...)
{
    // para imprimir messagebox quando necessario
    //#pragma comment (lib,"user32.lib")

    {
        int val;
        va_list ammannddaa;
        char buffer[20000];
        va_start(ammannddaa, format);
        vsprintf(buffer,
                 format, ammannddaa);
        val =
            MessageBoxA(0, buffer, "->Info", MB_OKCANCEL | MB_TOPMOST);
        va_end(ammannddaa);
        if (val != IDOK)
        {
            exit(1);
        }
    }
}

/**
 * @brief It will check to see if a valid instance was passed
 */
void check_mv_instance(__int64 mv_instance)
{

    cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r;

    if (0 == mv_instance)
    {
        mprintf("mv_instance cannot be 0, you need to call the function to create it first\n");
        exit(24);
    }

    a_ajtmampjv_r =
        (cardo___i___ava__a__aurora_boreal *)(__INT32_OR_INT64)
            mv_instance;

    if (0xbadc0da != a_ajtmampjv_r->sIgnature)
    {
        mprintf("Invalid signature for the mv_instance\n");
        exit(51);
    }
}
