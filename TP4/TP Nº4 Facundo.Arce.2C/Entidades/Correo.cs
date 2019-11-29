using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Entidades
{
    public class Correo : IMostrar<List<Paquete>>
    {
        public List<Thread> mockPaquetes;
        public List<Paquete> paquetes;

        #region Constructor
        public Correo()
        {
            this.mockPaquetes = new List<Thread>();
            this.paquetes = new List<Paquete>();
        }
        #endregion

        #region Propiedades
        /// <summary>
        ///     Get y Set para el atributo paquete.
        /// </summary>
        public List<Paquete> Paquetes
        {
            get { return this.paquetes; }
            set { this.paquetes = value; }
        }
        #endregion

        #region Sobrecargas
        /// <summary>
        ///     Agrega paquetes ala lista de paquetes del correo.
        /// </summary>
        /// <param name="c"></param>
        /// <param name="p"></param>
        /// <returns>Rorna la el correo con el paquete agregado.</returns>
        public static Correo operator +(Correo c, Paquete p)
        {
            /*if (c.Paquetes.Contains(p))
            {

            }*/
            bool aux = false;
            foreach (Paquete paquete in c.Paquetes)
            {
                if (paquete == p)
                {
                    aux = true;
                    break;
                }
            }
            if (aux != true)
            {
                try
                {
                    c.Paquetes.Add(p);
                    Thread hilo = new Thread(p.MockCicloDeVida);
                    c.mockPaquetes.Add(hilo);
                    hilo.Start();
                }
                catch (Exception e)
                {
                    throw e;
                }
            }
            else
            {
                throw new TrackingIdRepetidoException("El Tracking ID " + p.TrackingID.ToString() + " ya figura en la lista de envios");
            }

            return c;
        }
        /// <summary>
        ///     Muestra todos los datos del elemento pasado.
        /// </summary>
        /// <param name="elementos"></param>
        /// <returns>Retorna una cadena con los datos.</returns>
        public string MostrarDatos(IMostrar<List<Paquete>> elementos)
        {
            StringBuilder sb = new StringBuilder();
            
            foreach(Paquete p in ((Correo)elementos).Paquetes)
            {
                sb.AppendLine(string.Format("{0} para {1} ({2})", p.TrackingID, p.DireccionEntrega, p.Estado.ToString()));
            }

            return sb.ToString();
        }
        /// <summary>
        ///     Finaliza todos los hilos activos.
        /// </summary>
        public void FinEntregas()
        {
            foreach(Thread hilo in this.mockPaquetes)
            {
                hilo.Abort();
            }
        }
        #endregion
    }
}
