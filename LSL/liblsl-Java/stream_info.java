/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class stream_info {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected stream_info(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(stream_info obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        liblslJNI.delete_stream_info(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public stream_info(String name, String type, int channel_count, double nominal_srate, channel_format_t channel_format, String source_id) {
    this(liblslJNI.new_stream_info__SWIG_0(name, type, channel_count, nominal_srate, channel_format.swigValue(), source_id), true);
  }

  public stream_info(String name, String type, int channel_count, double nominal_srate, channel_format_t channel_format) {
    this(liblslJNI.new_stream_info__SWIG_1(name, type, channel_count, nominal_srate, channel_format.swigValue()), true);
  }

  public stream_info(String name, String type, int channel_count, double nominal_srate) {
    this(liblslJNI.new_stream_info__SWIG_2(name, type, channel_count, nominal_srate), true);
  }

  public stream_info(String name, String type, int channel_count) {
    this(liblslJNI.new_stream_info__SWIG_3(name, type, channel_count), true);
  }

  public stream_info(String name, String type) {
    this(liblslJNI.new_stream_info__SWIG_4(name, type), true);
  }

  public String name() {
    return liblslJNI.stream_info_name(swigCPtr, this);
  }

  public String type() {
    return liblslJNI.stream_info_type(swigCPtr, this);
  }

  public int channel_count() {
    return liblslJNI.stream_info_channel_count(swigCPtr, this);
  }

  public double nominal_srate() {
    return liblslJNI.stream_info_nominal_srate(swigCPtr, this);
  }

  public channel_format_t channel_format() {
    return channel_format_t.swigToEnum(liblslJNI.stream_info_channel_format(swigCPtr, this));
  }

  public String source_id() {
    return liblslJNI.stream_info_source_id(swigCPtr, this);
  }

  public int version() {
    return liblslJNI.stream_info_version(swigCPtr, this);
  }

  public double created_at() {
    return liblslJNI.stream_info_created_at(swigCPtr, this);
  }

  public String uid() {
    return liblslJNI.stream_info_uid(swigCPtr, this);
  }

  public String session_id() {
    return liblslJNI.stream_info_session_id(swigCPtr, this);
  }

  public String hostname() {
    return liblslJNI.stream_info_hostname(swigCPtr, this);
  }

  public xml_element desc() {
    return new xml_element(liblslJNI.stream_info_desc__SWIG_0(swigCPtr, this), true);
  }

  public String as_xml() {
    return liblslJNI.stream_info_as_xml(swigCPtr, this);
  }

  public int channel_bytes() {
    return liblslJNI.stream_info_channel_bytes(swigCPtr, this);
  }

  public int sample_bytes() {
    return liblslJNI.stream_info_sample_bytes(swigCPtr, this);
  }

  public SWIGTYPE_p_stream_info_impl impl() {
    long cPtr = liblslJNI.stream_info_impl__SWIG_0(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_stream_info_impl(cPtr, false);
  }

  public stream_info(SWIGTYPE_p_stream_info_impl impl) {
    this(liblslJNI.new_stream_info__SWIG_5(SWIGTYPE_p_stream_info_impl.getCPtr(impl)), true);
  }

  public stream_info() {
    this(liblslJNI.new_stream_info__SWIG_7(), true);
  }

  public stream_info(stream_info rhs) {
    this(liblslJNI.new_stream_info__SWIG_8(stream_info.getCPtr(rhs), rhs), true);
  }

}