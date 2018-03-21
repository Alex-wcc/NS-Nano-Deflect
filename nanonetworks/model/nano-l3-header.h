/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013,2014 TELEMATICS LAB, DEI - Politecnico di Bari
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
 * Author: Giuseppe Piro <peppe@giuseppepiro.com>, <g.piro@poliba.it>
 */


#ifndef NANO_L3_HEADER_H
#define NANO_L3_HEADER_H

#include <ns3/header.h>
#include <ns3/mac48-address.h>
#include <ns3/address-utils.h>

#define MAXTTLVALUE 1000

namespace ns3 {
/**
 * \ingroup nanonetworks
 *
 * This class implements the MAC header for nano nodes
 */
class NanoL3Header : public Header
{
public:
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  /**
   * \brief set the source id
   * \param source the source id
   */
  void SetSource (uint32_t source);
  /**
   * \brief set the the destination id
   * \param destination the destination id
   */
  void SetDestination (uint32_t destination);
  /**
   * \brief set the ttl
   * \param ttl the ttl value
   */
  void SetTtl (uint32_t ttl);
  /**
   * \brief set the packet id
   * \param id the packet id
   */
  void SetPacketId (uint32_t id);
  /**
   * \brief get the the source id
   * \return the source id
   */
  uint32_t GetSource () const;
  /**
   * \brief get the the destination id
   * \return the destination id
   */
  uint32_t GetDestination () const;
  /**
   * \brief get the the ttl
   * \return the ttl
   */
  uint32_t GetTtl () const;
  /**
   * \brief get the the packet id
   * \return the packet id
   */
  uint32_t GetPacketId () const;

//for the q value and hop count
  void SetQvalue(double qvalue);
  double GetQvalue() const;

  void SetHopCount(int hopcount);
  uint32_t GetHopCount() const;

  void SetPrevious(uint32_t previous);
  uint32_t GetPrevious() const;

  void SetQHopCount(uint32_t qhopcount);
  uint32_t GetQHopCount() const;



private:
  uint32_t m_source;
  uint32_t m_destination;
  uint32_t m_previous;
  uint32_t m_ttl;
  uint32_t m_packetId;
  double m_qvalue;
  uint32_t m_hopcount;
  uint32_t m_qhopcount;
};

} // namespace ns3

#endif /* NANO_L3_HEADER_H */