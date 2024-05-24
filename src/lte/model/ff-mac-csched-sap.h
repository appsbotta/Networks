/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Manuel Requena <manuel.requena@cttc.es>
 * Modified by: NIST // Contributions may not be subject to US copyright.
 */

#ifndef FF_MAC_CSCHED_SAP_H
#define FF_MAC_CSCHED_SAP_H

#include <stdint.h>
#include <vector>

#include "ff-mac-common.h"
#include "lte-sl-pool.h"

namespace ns3 {

/**
 * \ingroup ff-api
 * \brief Provides the CSCHED SAP
 *
 * This abstract class defines the MAC Scheduler interface specified in the
 * Femto Forum Technical Document:
 *   - LTE MAC Scheduler Interface Specification v1.11
 *
 * The Technical Document contains a detailed description of the API.
 * The documentation of this class refers to sections of this Technical Document.
 *
 * You can found an example of the implementation of this interface
 * in the SampleFfMacCschedSapProvider and SampleFfMacCschedSapuser classes
 */
class FfMacCschedSapProvider
{
public:
  virtual ~FfMacCschedSapProvider ();

  /**
   * Parameters of the API primitives
   */

  /**
   * Parameters of the CSCHED_CELL_CONFIG_REQ primitive.
   * See section 4.1.1 for a detailed description of the parameters.
   */
  struct CschedCellConfigReqParameters
  {
    uint8_t m_puschHoppingOffset; ///< pusch hopping offset

    /// Hopping mode enumeration
    enum HoppingMode_e
    {
      inter,
      interintra
    } m_hoppingMode; ///< hopping mode

    uint8_t m_nSb; ///< unused

    /// PHICH resource enumeration
    enum PhichResource_e
    {
      PHICH_R_ONE_SIXTH,
      PHICH_R_HALF,
      PHICH_R_ONE,
      PHICH_R_TWO
    } m_phichResource; ///< PHICH resource


    enum NormalExtended_e m_phichDuration; ///< PHICH duration

    uint8_t m_initialNrOfPdcchOfdmSymbols; ///< initial number of PDCCH OFDM symbols

    struct SiConfiguration_s m_siConfiguration; ///< SI configuration

    uint16_t m_ulBandwidth; ///< UL bandwidth
    uint16_t m_dlBandwidth; ///< DL badnwidth

    enum NormalExtended_e m_ulCyclicPrefixLength; ///< UL cyclic prefix length
    enum NormalExtended_e m_dlCyclicPrefixLength; ///< DL cyclic prefix length

    uint8_t m_antennaPortsCount; ///< antenna port count

    /// Duplex mode enumeration
    enum DuplexMode_e
    {
      DM_TDD,
      DM_FDD
    } m_duplexMode; ///< duplex mode

    uint8_t m_subframeAssignment; ///< subframe assignment
    uint8_t m_specialSubframePatterns; ///< special subframe patterns
    std::vector <uint8_t> m_mbsfnSubframeConfigRfPeriod; ///< MBS subframe config RF period
    std::vector <uint8_t> m_mbsfnSubframeConfigRfOffset; ///< MBS subframe config RF offset
    std::vector <uint8_t> m_mbsfnSubframeConfigSfAllocation; ///< MBS subframe config SF allocation
    uint8_t m_prachConfigurationIndex; ///< prach configuration index
    uint8_t m_prachFreqOffset; ///< prach frequency offset
    uint8_t m_raResponseWindowSize; ///< response window size
    uint8_t m_macContentionResolutionTimer; ///< MAC contention resolution timer
    uint8_t m_maxHarqMsg3Tx; ///< maximum HARQ message 3 transmit 
    uint16_t m_n1PucchAn; ///< n1pu cch an
    uint8_t m_deltaPucchShift; ///< delta pu cch shift
    uint8_t m_nrbCqi; ///< nrb CQI
    uint8_t m_ncsAn; ///< ncs an
    uint8_t m_srsSubframeConfiguration; ///< SRS subframe configuration
    uint8_t m_srsSubframeOffset; ///< SRS subframe offset
    uint8_t m_srsBandwidthConfiguration; ///< SFractional Frequency Reuse (FFR) is an interference mitigation scheme which allows the use of different frequency reuse factors over different frequency partitions in certain time intervals in downlink and uplink transmissions.RS bandwidth configuration
    bool    m_srsMaxUpPts; ///< SRS maximum up pts

    /// Enable64Qam_e enumeration
    enum Enable64Qam_e
    {
      MOD_16QAM,
      MOD_64QAM
    } m_enable64Qam; ///< enable64Qam

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  /**
   * Parameters of the CSCHED_UE_CONFIG_REQ primitive.
   * See section 4.1.3 for a detailed description of the parameters.
   */
  /// CschedUeConfigReqParameters structure
  struct CschedUeConfigReqParameters
  {
    uint16_t  m_rnti; ///< RNTI
    bool      m_reconfigureFlag; ///< reconfigure flag
    bool      m_drxConfigPresent; ///< drx config present
    struct DrxConfig_s m_drxConfig; ///< drx config
    uint16_t  m_timeAlignmentTimer; ///< time alignment timer

    /// MeasGapConfigPattern_e enumaration
    enum MeasGapConfigPattern_e
    {
      MGP_GP1,
      MGP_GP2,
      OFF
    } m_measGapConfigPattern; ///< measGapConfigPattern

    uint8_t   m_measGapConfigSubframeOffset; ///< measure gap config subframe offset
    bool      m_spsConfigPresent; ///< SPS configu present
    struct SpsConfig_s m_spsConfig; ///< SPS config
    bool      m_srConfigPresent; ///< SR config present
    struct SrConfig_s m_srConfig; ///< SR config
    bool      m_cqiConfigPresent; ///< CQI config present
    struct CqiConfig_s m_cqiConfig; ///< CQI config
    uint8_t   m_transmissionMode; ///< transmission mode
    uint64_t  m_ueAggregatedMaximumBitrateUl; ///< UE aggregate maximum bit rate UL
    uint64_t  m_ueAggregatedMaximumBitrateDl; ///< UE aggregate maximum bit rate DL
    struct UeCapabilities_s m_ueCapabilities; ///< UE capabilities

    /// OpenClosedLoop_e
    enum OpenClosedLoop_e
    {
      noneloop,
      openloop,
      closedloop
    } m_ueTransmitAntennaSelection; ///< ueTransmitAntennaSelection

    bool      m_ttiBundling; ///< TTI bundling
    uint8_t   m_maxHarqTx; ///< maximum HARQ transmit
    uint8_t   m_betaOffsetAckIndex; ///< beta offset ack index
    uint8_t   m_betaOffsetRiIndex; ///< beta offset ri index
    uint8_t   m_betaOffsetCqiIndex; ///< beta offset CQI index
    bool      m_ackNackSrsSimultaneousTransmission; ///< ack nack SRS simultaneous transmission
    bool      m_simultaneousAckNackAndCqi; ///< simultaneous ack nack and CQI

    /// RepMode_e enumeration
    enum RepMode_e
    {
      rm12, rm20, rm22, rm30, rm31, nonemode
    } m_aperiodicCqiRepMode; ///< aperiodicCqiRepMode

    /// FeedbackMode_e enumeration
    enum FeedbackMode_e
    {
      bundling,
      multiplexing
    } m_tddAckNackFeedbackMode; ///< tddAckNackFeedbackMode

    uint8_t   m_ackNackRepetitionFactor; ///< ackNackRepetitionFactor

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList

    std::vector <uint32_t> m_slDestinations; ///< List of Sidelink destinations
  };

  /**
   * Parameters of the CSCHED_LC_CONFIG_REQ primitive.
   * See section 4.1.5 for a detailed description of the parameters.
   */
  struct CschedLcConfigReqParameters
  {
    uint16_t  m_rnti; ///< RNTI
    bool      m_reconfigureFlag; ///< reconfigure flag

    std::vector <struct LogicalChannelConfigListElement_s> m_logicalChannelConfigList; ///< logicalChannelConfigList

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList
  };

  /**
   * Parameters of the CSCHED_LC_RELEASE_REQ primitive.
   * See section 4.1.7 for a detailed description of the parameters.
   */
  struct CschedLcReleaseReqParameters
  {
    uint16_t  m_rnti; ///< RNTI

    std::vector <uint8_t> m_logicalChannelIdentity; ///< logical channel identity

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList
  };

  /**
   * Parameters of the CSCHED_UE_RELEASE_REQ primitive.
   * See section 4.1.9 for a detailed description of the parameters.
   */
  struct CschedUeReleaseReqParameters
  {
    uint16_t  m_rnti; ///< RNTI

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList
  };
  /**
   * Parameters to setup a Sidelink communication pool
   */
  struct CschedPoolConfigReqParameters
  {
    uint32_t m_group; ///< Group id
    Ptr<SidelinkCommResourcePool> m_pool; ///< Sidelink communication resource pool
  };  
  /**
   * Parameters to release a Sidelink communication pool
   */
  struct CschedPoolReleaseReqParameters
  {
    uint32_t m_group; ///< group id
  };
  /**
   * Parameters to setup a Sidelink discovery pool
   */
  struct CschedDiscPoolConfigReqParameters
  {
    uint32_t m_discTxResourceReq; ///< Number of resources the UE requires every discovery period
    Ptr<SidelinkDiscResourcePool> m_pool; ///< Sidelink discovery resource pool
  };

  /**
   * Parameters to release a Sidelink discovery pool
   */
  struct CschedDiscPoolReleaseReqParameters
  {
    uint32_t m_discTxResourceReq; ///< Number of discovery resources to release
  };

  //
  // CSCHED - MAC Scheduler Control SAP primitives
  // (See 4.1 for description of the primitives)
  //

  /**
   * \brief CSCHED_CELL_CONFIG_REQ
   *
   * \param params CschedCellConfigReqParameters
   */
  virtual void CschedCellConfigReq (const struct CschedCellConfigReqParameters& params) = 0;

  /**
   * \brief CSCHED_UE_CONFIG_REQ
   *
   * \param params CschedUeConfigReqParameters
   */
  virtual void CschedUeConfigReq (const struct CschedUeConfigReqParameters& params) = 0;

  /**
   * \brief CSCHED_LC_CONFIG_REQ
   *
   * \param params CschedLcConfigReqParameters
   */
  virtual void CschedLcConfigReq (const struct CschedLcConfigReqParameters& params) = 0;

  /**
   * \brief CSCHED_LC_RELEASE_REQ
   *
   * \param params CschedLcReleaseReqParameters
   */
  virtual void CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params) = 0;

  /**
   * \brief CSCHED_UE_RELEASE_REQ
   *
   * \param params CschedUeReleaseReqParameters
   */
  virtual void CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params) = 0;

  //we are not making those function purely virtual so not all templates need to support them
  /**
   * \brief CSCHED_POOL_CONFIG_REQ
   *
   * \param params CschedPoolConfigReqParameters
   */
  virtual void CschedPoolConfigReq (const struct CschedPoolConfigReqParameters& params) {};
  /**
   * \brief CSCHED_POOL_RELEASE_REQ
   *
   * \param params CschedPoolConfigReqParameters
   *
   */
  virtual void CschedPoolReleaseReq (const struct CschedPoolReleaseReqParameters& params) {};
  /**
   * \brief CSCHED_DISC_POOL_CONFIG_REQ
   *
   * \param params CschedDiscPoolConfigReqParameters
   */
  virtual void CschedDiscPoolConfigReq (const struct CschedDiscPoolConfigReqParameters& params) {};
  /**
   * \brief CSCHED_DISC_POOL_RELEASE_REQ
   *
   * \param params CschedDiscPoolConfigReqParameters
   */
  virtual void CschedDiscPoolReleaseReq (const struct CschedDiscPoolReleaseReqParameters& params) {};

private:
};


/**
 * FfMacCschedSapUser class
 */
class FfMacCschedSapUser
{
public:
  virtual ~FfMacCschedSapUser ();

  /**
   * Parameters of the API primitives
   */

  /**
   * Parameters of the CSCHED_CELL_CONFIG_CNF primitive.
   * See section 4.1.2 for a detailed description of the parameters.
   */
  struct CschedCellConfigCnfParameters
  {
    enum Result_e m_result; ///< result

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList
  };

  /**
   * Parameters of the CSCHED_UE_CONFIG_CNF primitive.
   * See section 4.1.4 for a detailed description of the parameters.
   */
  struct CschedUeConfigCnfParameters
  {
    uint16_t  m_rnti; ///< RNTI
    enum Result_e m_result; ///< result

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendorSpecificList
  };

  /**
   * Parameters of the CSCHED_LC_CONFIG_CNF primitive.
   * See section 4.1.6 for a detailed description of the parameters.
   */
  struct CschedLcConfigCnfParameters
  {
    uint16_t  m_rnti; ///< RNTI
    enum Result_e m_result; ///< result

    std::vector <uint8_t> m_logicalChannelIdentity; ///< logical channel identity

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  /**
   * Parameters of the CSCHED_LC_RELEASE_CNF primitive.
   * See section 4.1.8 for a detailed description of the parameters.
   */
  struct CschedLcReleaseCnfParameters
  {
    uint16_t  m_rnti; ///< RNTI
    enum Result_e m_result; ///< result

    std::vector <uint8_t> m_logicalChannelIdentity; ///< logical channel identity

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  /**
   * Parameters of the CSCHED_UE_RELEASE_CNF primitive.
   * See section 4.1.10 for a detailed description of the parameters.
   */
  struct CschedUeReleaseCnfParameters
  {
    uint16_t  m_rnti; ///< RNTI
    enum Result_e m_result; ///< result

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  /**
   * Parameters of the CSCHED_UE_CONFIG_UPDATE_IND primitive.
   * See section 4.1.11 for a detailed description of the parameters.
   */
  struct CschedUeConfigUpdateIndParameters
  {
    uint16_t  m_rnti; ///< RNTI
    uint8_t   m_transmissionMode; ///< transmission mode
    bool      m_spsConfigPresent; ///< SPS config present
    struct SpsConfig_s m_spsConfig; ///< SPS config
    bool      m_srConfigPresent; ///< SR config present
    struct SrConfig_s m_srConfig; ///< SR config
    bool      m_cqiConfigPresent; ///< CQI config present
    struct CqiConfig_s m_cqiConfig; ///< CQI config

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  /**
   * Parameters of the CSCHED_CELL_CONFIG_UPDATE_IND primitive.
   * See section 4.1.12 for a detailed description of the parameters.
   */
  struct CschedCellConfigUpdateIndParameters
  {
    uint8_t   m_prbUtilizationDl; ///< DL utilization
    uint8_t   m_prbUtilizationUl; ///< UL utilization

    std::vector <struct VendorSpecificListElement_s> m_vendorSpecificList; ///< vendor specific list
  };

  //
  // CSCHED - MAC Scheduler Control SAP primitives
  // (See 4.1 for description of the primitives)
  //

  /**
   * \brief CSCHED_CELL_CONFIG_CNF
   *
   * \param params CschedCellConfigCnfParameters
   */
  virtual void CschedCellConfigCnf (const struct CschedCellConfigCnfParameters& params) = 0;

  /**
   * \brief CSCHED_UE_CONFIG_CNF
   *
   * \param params CschedUeConfigCnfParameters
   */
  virtual void CschedUeConfigCnf (const struct CschedUeConfigCnfParameters& params) = 0;

  /**
   * \brief CSCHED_LC_CONFIG_CNF
   *
   * \param params CschedLcConfigCnfParameters
   */
  virtual void CschedLcConfigCnf (const struct CschedLcConfigCnfParameters& params) = 0;

  /**
   * \brief CSCHED_LC_RELEASE_CNF
   *
   * \param params CschedLcReleaseCnfParameters
   */
  virtual void CschedLcReleaseCnf (const struct CschedLcReleaseCnfParameters& params) = 0;

  /**
   * \brief CSCHED_UE_RELEASE_CNF
   *
   * \param params CschedUeReleaseCnfParameters
   */
  virtual void CschedUeReleaseCnf (const struct CschedUeReleaseCnfParameters& params) = 0;

  /**
   * \brief CSCHED_UE_UPDATE_IND
   *
   * \param params CschedUeConfigUpdateIndParameters
   */
  virtual void CschedUeConfigUpdateInd (const struct CschedUeConfigUpdateIndParameters& params) = 0;

  /**
   * \brief CSCHED_UE_CONFIG_IND
   *
   * \param params CschedCellConfigUpdateIndParameters
   */
  virtual void CschedCellConfigUpdateInd (const struct CschedCellConfigUpdateIndParameters& params) = 0;

private:
};


/// MemberCschedSapProvider class
template <class C>
class MemberCschedSapProvider : public FfMacCschedSapProvider
{
public:
  /**
   * Constructor
   *
   * \param scheduler the scheduler class
   */
  MemberCschedSapProvider (C* scheduler);

  // inherited from FfMacCschedSapProvider
  virtual void CschedCellConfigReq (const struct CschedCellConfigReqParameters& params);
  virtual void CschedUeConfigReq (const struct CschedUeConfigReqParameters& params);
  virtual void CschedLcConfigReq (const struct CschedLcConfigReqParameters& params);
  virtual void CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params);
  virtual void CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params);

private:
  MemberCschedSapProvider ();
  C* m_scheduler; ///< scheduler class
};

template <class C>
MemberCschedSapProvider<C>::MemberCschedSapProvider ()
{
}

template <class C>
MemberCschedSapProvider<C>::MemberCschedSapProvider (C* scheduler) : m_scheduler (scheduler)
{
}

template <class C>
void
MemberCschedSapProvider<C>::CschedCellConfigReq (const struct CschedCellConfigReqParameters& params)
{
  m_scheduler->DoCschedCellConfigReq (params);
}

template <class C>
void
MemberCschedSapProvider<C>::CschedUeConfigReq (const struct CschedUeConfigReqParameters& params)
{
  m_scheduler->DoCschedUeConfigReq (params);
}

template <class C>
void
MemberCschedSapProvider<C>::CschedLcConfigReq (const struct CschedLcConfigReqParameters& params)
{
  m_scheduler->DoCschedLcConfigReq (params);
}

template <class C>
void
MemberCschedSapProvider<C>::CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params)
{
  m_scheduler->DoCschedLcReleaseReq (params);
}

template <class C>
void
MemberCschedSapProvider<C>::CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params)
{
  m_scheduler->DoCschedUeReleaseReq (params);
}


/// MemberCschedSlSapProvider class
template <class C>
class MemberCschedSlSapProvider : public FfMacCschedSapProvider
{
public:
  /**
   * Constructor
   *
   * \param scheduler the scheduler class
   */
  MemberCschedSlSapProvider (C* scheduler);

  // inherited from FfMacCschedSapProvider
  virtual void CschedCellConfigReq (const struct CschedCellConfigReqParameters& params);
  virtual void CschedUeConfigReq (const struct CschedUeConfigReqParameters& params);
  virtual void CschedLcConfigReq (const struct CschedLcConfigReqParameters& params);
  virtual void CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params);
  virtual void CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params);
  virtual void CschedPoolConfigReq (const struct CschedPoolConfigReqParameters& params);  
  virtual void CschedPoolReleaseReq (const struct CschedPoolReleaseReqParameters& params);
  virtual void CschedDiscPoolConfigReq (const struct CschedDiscPoolConfigReqParameters& params);
  virtual void CschedDiscPoolReleaseReq (const struct CschedDiscPoolReleaseReqParameters& params);

private:
  MemberCschedSlSapProvider ();
  C* m_scheduler; ///< scheduler class
};

template <class C>
MemberCschedSlSapProvider<C>::MemberCschedSlSapProvider ()
{
}

template <class C>
MemberCschedSlSapProvider<C>::MemberCschedSlSapProvider (C* scheduler) : m_scheduler (scheduler)
{
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedCellConfigReq (const struct CschedCellConfigReqParameters& params)
{
  m_scheduler->DoCschedCellConfigReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedUeConfigReq (const struct CschedUeConfigReqParameters& params)
{
  m_scheduler->DoCschedUeConfigReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedLcConfigReq (const struct CschedLcConfigReqParameters& params)
{
  m_scheduler->DoCschedLcConfigReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedLcReleaseReq (const struct CschedLcReleaseReqParameters& params)
{
  m_scheduler->DoCschedLcReleaseReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedUeReleaseReq (const struct CschedUeReleaseReqParameters& params)
{
  m_scheduler->DoCschedUeReleaseReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedPoolConfigReq (const struct CschedPoolConfigReqParameters& params)
{
  m_scheduler->DoCschedPoolConfigReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedPoolReleaseReq (const struct CschedPoolReleaseReqParameters& params)
{
  m_scheduler->DoCschedPoolReleaseReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedDiscPoolConfigReq (const struct CschedDiscPoolConfigReqParameters& params)
{
  m_scheduler->DoCschedDiscPoolConfigReq (params);
}

template <class C>
void
MemberCschedSlSapProvider<C>::CschedDiscPoolReleaseReq (const struct CschedDiscPoolReleaseReqParameters& params)
{
  m_scheduler->DoCschedDiscPoolReleaseReq (params);
}


} // end namespace ns3

#endif /* FF_MAC_CSCHED_SAP_H */