#include "Main.h"
#include "configfile.h"

class AMUSE_SimpleX : public SimpleX {

  friend class SimpleX;

  public:

    AMUSE_SimpleX(string output_path): SimpleX(output_path) {
        total_time=0.;
        syncflag=-1;
    };
    ~AMUSE_SimpleX(){};
    int add_vertex(long *id, double x,double y,double z,double rho,
                                           double flux,double xion);
    int add_site(long *id, double x,double y,double z,double rho,
                                           double flux,double xion);
    int remove_site(long id);
    int setup_simplex();
    
    void convert_units();
    
    int initialize(double current_time);
    int reinitialize();
    int evolve(double dt, int sync);
    int get_site(int id, double *x,double *y,double *z,double *rho,
                                           double *flux,double *xion);
    int get_position(int id, double *x, double *y, double *z);
    int get_density(int id, double *rho);
    int get_flux(int id, double *flux);
    int get_ionisation(int id, double *xion);
    int set_site(int id, double x, double y, double z, double rho,
                                           double flux, double xion);
    int set_position(int id, double x, double y, double z);
    int set_density(int id, double rho);
    int set_flux(int id, double flux);
    int set_ionisation(int id, double xion);
    int cleanup();
    int get_syncflag(){return syncflag;}
    int set_UNIT_T(double ts){ UNIT_T=ts;return 0;}
    int get_UNIT_T(double *ts){ *ts=UNIT_T;return 0;}
    int set_sizeBox(double bs){ sizeBox=bs;return 0;}
    int get_sizeBox(double *bs){ *bs=sizeBox;return 0;}
    int set_hilbert_order(int ho){ hilbert_order=ho;return 0;}
    int get_hilbert_order(int *ho){ *ho=hilbert_order;return 0;}


  private:

    void read_parameters();
    double total_time;     
    int syncflag; 
};
