using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades
{
    public static class GuardarString
    {
        /// <summary>
        ///     Metodo de extencion de string que guada el texto en un archivo.
        /// </summary>
        /// <param name="texto"></param>
        /// <param name="archivo"></param>
        /// <returns>Retorna True si tubo exito, de lo contrario false.</returns>
        public static bool Guardar(this string texto, string archivo)
        {
            bool rta = false;
            StreamWriter sw = new StreamWriter(string.Format(@"{0}\{1}", Environment.GetFolderPath(Environment.SpecialFolder.Desktop), archivo));
            try
            {

                sw.WriteLine(texto);
                rta = true;

            }
            catch (Exception e)
            {
                throw e;
            }
            finally
            {
                sw.Close();
            }

            return rta;
        }
    }
}
