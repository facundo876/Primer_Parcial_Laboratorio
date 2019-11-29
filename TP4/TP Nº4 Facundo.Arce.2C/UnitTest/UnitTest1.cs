using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Entidades;

namespace UnitTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestPaquetesDeCorreoInstanciado()
        {
            Correo correo;

            correo = new Correo();

            Assert.IsNotNull(correo.paquetes);
        }

        [TestMethod]
        [ExpectedException(typeof(TrackingIdRepetidoException))]
        public void TestTrackingIdRepetido()
        {
            Correo corre = new Correo();
            Paquete paquete1 = new Paquete("Mitre", "00001");
            Paquete paquete2 = new Paquete("Mitre", "00001");

            corre += paquete1;
            corre += paquete2;
        }
        
    }
}
