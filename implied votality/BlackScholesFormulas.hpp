//
//  BlackScholesFormulas.hpp
//  joshi_chp9
//
//  Created by Matthew liew on 22.10.23.
//

#ifndef BlackScholesFormulas_hpp
#define BlackScholesFormulas_hpp

double BlackScholesCall(double Spot,
                        double Strike,
                        double r,
                        double d,
                        double Vol,
                        double Expiry);

double BlackScholesCallVega(double Spot,
                                double Strike,
                                double r,
                                double d,
                                double Vol,
                                double Expiry);

//double BlackScholesPut(double Spot,
//                          double Strike,
//                          double r,
//                          double d,
//                          double Vol,
//                          double Expiry);
//
//double BlackScholesDigitalCall(double Spot,
//                               double Strike,
//                               double r,
//                               double d,
//                               double Vol,
//                               double Expiry);

    
#endif /* BlackScholesFormulas_hpp */
