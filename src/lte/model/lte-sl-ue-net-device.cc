/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * NIST-developed software is provided by NIST as a public
 * service. You may use, copy and distribute copies of the software in
 * any medium, provided that you keep intact this entire notice. You
 * may improve, modify and create derivative works of the software or
 * any portion of the software, and you may copy and distribute such
 * modifications or works. Modified works should carry a notice
 * stating that you changed the software and should note the date and
 * nature of any such change. Please explicitly acknowledge the
 * National Institute of Standards and Technology as the source of the
 * software.
 *
 * NIST-developed software is expressly provided "AS IS." NIST MAKES
 * NO WARRANTY OF ANY KIND, EXPRESS, IMPLIED, IN FACT OR ARISING BY
 * OPERATION OF LAW, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
 * NON-INFRINGEMENT AND DATA ACCURACY. NIST NEITHER REPRESENTS NOR
 * WARRANTS THAT THE OPERATION OF THE SOFTWARE WILL BE UNINTERRUPTED
 * OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE CORRECTED. NIST DOES NOT
 * WARRANT OR MAKE ANY REPRESENTATIONS REGARDING THE USE OF THE
 * SOFTWARE OR THE RESULTS THEREOF, INCLUDING BUT NOT LIMITED TO THE
 * CORRECTNESS, ACCURACY, RELIABILITY, OR USEFULNESS OF THE SOFTWARE.
 *
 * You are solely responsible for determining the appropriateness of
 * using and distributing the software and you assume all risks
 * associated with its use, including but not limited to the risks and
 * costs of program errors, compliance with applicable laws, damage to
 * or loss of data, programs or equipment, and the unavailability or
 * interruption of operation. This software is not intended to be used
 * in any situation where a failure could cause risk of injury or
 * damage to property. The software developed by NIST employees is not
 * subject to copyright protection within the United States.
 */

#include "lte-sl-ue-net-device.h"
#include "lte-ue-rrc.h"
#include "epc-ue-nas.h"
#include <ns3/ipv4-l3-protocol.h>
#include <ns3/ipv6-l3-protocol.h>
#include <ns3/log.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("LteSlUeNetDevice");

NS_OBJECT_ENSURE_REGISTERED ( LteSlUeNetDevice);


TypeId LteSlUeNetDevice::GetTypeId (void)
{
  static TypeId
    tid =
    TypeId ("ns3::LteSlUeNetDevice")
    .SetParent<LteNetDevice> ()
    .AddConstructor<LteSlUeNetDevice> ()
    .AddAttribute ("EpcUeNas",
                   "The NAS associated to this UeNetDevice",
                   PointerValue (),
                   MakePointerAccessor (&LteSlUeNetDevice::m_nas),
                   MakePointerChecker <EpcUeNas> ())
  ;

  return tid;
}


LteSlUeNetDevice::LteSlUeNetDevice (void)
{
  NS_LOG_FUNCTION (this);
}

LteSlUeNetDevice::~LteSlUeNetDevice (void)
{
  NS_LOG_FUNCTION (this);
}

void
LteSlUeNetDevice::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_nas = 0;
  LteNetDevice::DoDispose ();
}

void
LteSlUeNetDevice::SetNas (const Ptr<EpcUeNas> nas)
{
  NS_LOG_FUNCTION (this);
  m_nas = nas;
}

Ptr<EpcUeNas>
LteSlUeNetDevice::GetNas (void) const
{
  NS_LOG_FUNCTION (this);
  return m_nas;
}

void
LteSlUeNetDevice::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
}

bool
LteSlUeNetDevice::Send (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
  NS_LOG_FUNCTION (this << dest << protocolNumber);
  if (protocolNumber != Ipv4L3Protocol::PROT_NUMBER && protocolNumber != Ipv6L3Protocol::PROT_NUMBER)
    {
      NS_LOG_INFO ("unsupported protocol " << protocolNumber << ", only IPv4 and IPv6 are supported");
      return true;
    }
  return m_nas->Send (packet,protocolNumber);
}


} // namespace ns3
