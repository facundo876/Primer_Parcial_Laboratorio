using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;


namespace Entidades
{
    public class PaqueteDAO
    {
        private static SqlCommand comando;
        private static SqlConnection conexion;

        #region Contructor
            static PaqueteDAO()
            {
                //conexion = new SqlConnection("Data Source =SERVIDOR; Initial Catalog = correo-sp-2017; Integrated Security = True");
                conexion = new SqlConnection(@"Data Source=.\; Initial Catalog = correo-sp-2017; Integrated Security = True");
                comando = new SqlCommand();
            }
        #endregion

        #region Metodos
        /// <summary>
        ///     Guarda los datos del paquete en la base de datos.
        /// </summary>
        /// <param name="p"></param>
        /// <returns></returns>
        public static bool Insertar(Paquete p)
        {
            bool rta = false;
            try
            {
                comando.CommandType = System.Data.CommandType.Text;
                comando.Connection = conexion;
                conexion.Open();
                comando.CommandText = string.Format("INSERT INTO [correo-sp-2017].[dbo].[Paquetes] ([direccionEntrega],[trackingID],[alumno])" +
                                        "VALUES('{0}','{1}', '{2}')", p.DireccionEntrega, p.TrackingID, "Facundo Arce");

                comando.ExecuteNonQuery();
                rta = true;
            }
            catch (Exception e)
            {
                throw e;
            }
            finally
            {
                conexion.Close();
            }
            return rta;        
        }
    
        #endregion

    } 
}
