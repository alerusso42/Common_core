#!/bin/bash

# =================================================================
# SCRIPT DI INSTALLAZIONE E CONFIGURAZIONE PERF (LINUX PROFILING)
# =================================================================

# Verifica se lo script è eseguito come root
if [ "$EUID" -ne 0 ]; then 
  echo "Per favore, esegui lo script con sudo."
  exit
fi

echo "--- 1. Identificazione versione Kernel ---"
KERNEL_VERSION=$(uname -r)
echo "Versione kernel rilevata: $KERNEL_VERSION"

echo "--- 2. Installazione pacchetti necessari ---"
# Aggiorna i repository
apt-get update

# Installa la versione di perf specifica per il tuo kernel corrente
# Installa anche binutils per il disassembling (objdump)
apt-get install -y linux-tools-common linux-tools-generic linux-tools-$KERNEL_VERSION binutils

echo "--- 3. Configurazione permessi del Kernel (Sysctl) ---"

# kernel.perf_event_paranoid: 
# -1: Permette tutto (raccomandato per debug)
#  0: Permette accesso a CPU cycles e istruzioni utente/kernel
#  1: (Default) Permette solo kernel e user senza CPU-wide
echo "Settaggio perf_event_paranoid a -1..."
sysctl -w kernel.perf_event_paranoid=-1

# kernel.kptr_restrict:
#  0: Rende visibili gli indirizzi delle funzioni del kernel (risolve il problema dei simboli)
echo "Settaggio kptr_restrict a 0..."
sysctl -w kernel.kptr_restrict=0

# Rendere le modifiche permanenti (opzionale, scrive in /etc/sysctl.conf)
echo "Rendendo le modifiche permanenti in /etc/sysctl.conf..."
grep -qq "kernel.perf_event_paranoid" /etc/sysctl.conf || echo "kernel.perf_event_paranoid = -1" >> /etc/sysctl.conf
grep -qq "kernel.kptr_restrict" /etc/sysctl.conf || echo "kernel.kptr_restrict = 0" >> /etc/sysctl.conf

echo "--- 4. Verifica installazione ---"
if perf --version; then
    echo "INSTALLAZIONE COMPLETATA CON SUCCESSO!"
else
    echo "ERRORE durante l'installazione."
    exit 1
fi

echo "-------------------------------------------------------"
echo "GUIDA RAPIDA ALL'USO:"
echo "-------------------------------------------------------"
echo "1.1. Registra dati per il tuo binario (User Space + Kernel Space):"
echo "   perf record ./a.out"
echo "OPPURE"
echo "1.2. Registra dati solo per user space:"
echo "   perf record -e cycles:u ./a.out"
echo ""
echo "2. Visualizza il report:"
echo "   perf report"
echo ""
echo "3. Per vedere l'assembly:"
echo "   Dentro il report, seleziona una funzione e premi invio"
echo "-------------------------------------------------------"