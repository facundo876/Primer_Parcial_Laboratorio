using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Entidades
{
    public class Paquete : IMostrar<Paquete>
    {
        private string direccionEntrega;
        private EEstado estado;
        private string trackingID;

        public enum EEstado { Ingresado, EnViaje, Entregado }

        public delegate void DelegadoEstado(object sender, EventArgs e);

        public event DelegadoEstado InfornmarEstado;

        #region Contructor
        public Paquete(string direccionEntrega, string trackingID)
        {
            
            this.direccionEntrega = direccionEntrega;
            this.estado = EEstado.Ingresado;
            this.trackingID = trackingID;
            
        }
        #endregion

        #region Propiedades
        /// <summary>
        ///     Get y Set del atributo DireccionEntregas.
        /// </summary>
        public string DireccionEntrega
        {
            get { return this.direccionEntrega; }
            set { this.direccionEntrega = value; }
        }
        /// <summary>
        ///     Get y Set del atributo Estado.
        /// </summary>
        public EEstado Estado
        {
            get { return this.estado; }
            set { this.estado = value; }

        }
        /// <summary>
        ///     Get y Set del atributo TrackingID.
        /// </summary>
        public string TrackingID
        {
            get { return this.trackingID; }
            set { this.trackingID = value; }
        }
        #endregion

        #region Metodos
        /// <summary>
        ///     Cambia el estado del paquete cada hasta que este sea entregado y lo guarda en la base de datos.
        /// </summary>
        public void MockCicloDeVida()
        {
            do
            {
                
                if(this.estado == EEstado.Ingresado)
                {
                    Thread.Sleep(4000);
                    this.estado = EEstado.EnViaje;
                }
                else if (this.estado == EEstado.EnViaje)
                {
                    Thread.Sleep(4000);
                    this.estado = EEstado.Entregado;
                }

                this.InfornmarEstado.Invoke(this, EventArgs.Empty);

            } while (this.estado != EEstado.Entregado);

            try
            {
                PaqueteDAO.Insertar(this);
            }
            catch(Exception)
            {
                throw new Exception("Error! Al momento de guardar en la base de datos");
            }
        }
        /// <summary>
        ///     Muestra los datos del elemento paquete pasado por parametos.
        /// </summary>
        /// <param name="elemento"></param>
        /// <returns>Retorna un cadenaa con la informacion del elemento.</returns>
        public string MostrarDatos(IMostrar<Paquete> elemento)
        {
            Paquete p = (Paquete)elemento;
            return string.Format("{0} para {1}", p.trackingID, p.direccionEntrega);
        }

        #endregion

        #region Sobrecargas
        /// <summary>
        ///     Sobrecarga del ToString para Paquete.
        /// </summary>
        /// <returns>Retorna los datos del paquete.</returns>
        public override string ToString()
        {
            return this.MostrarDatos(this);
        }
        /// <summary>
        ///     Compara si dos paquetes son iguales.
        /// </summary>
        /// <param name="p1"></param>
        /// <param name="p2"></param>
        /// <returns>Retorna True si lo son, de lo contrario false.</returns>
        public static bool operator ==(Paquete p1, Paquete p2)
        {
            if (p1.TrackingID == p2.TrackingID)
            {
                return true;
            }
            return false;
        }
        /// <summary>
        ///     Compara si dos paquetes son diferenctes.
        /// </summary>
        /// <param name="p1"></param>
        /// <param name="p2"></param>
        /// <returns>Retorna true si lo son, de lo contrario false.</returns>
        public static bool operator !=(Paquete p1, Paquete p2)
        {
            return !(p1 == p2);
        }
        #endregion
    }
}
